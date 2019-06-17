//! the subsystem that governs the timing of the game engine

use std::cell::{Cell};
use std::time::{Duration, Instant};

#[cfg(test)]
mod test;

/// convert a duration to a 64-bit float representing a number of seconds (not multithread-friendly)
/// NOTE: this will be replaced with Duration::as_seconds_f64 as soon as issue github.com/rust-lang/rust/issues/54361 is stabilized.
pub fn duration_to_seconds (duration: Duration) -> f64 {
    return duration.as_secs() as f64 + (duration.subsec_nanos() as f64 * 1E-9f64);
}

/// convert a floating point number of seconds to a duration (not multithread-friendly)
/// NOTE: this will be replaced with Duration::from_seconds_f64 as soon as issue github.com/rust-lang/rust/issues/54361 is stabilized.
pub fn seconds_to_duration (seconds: f64) -> Duration {
    return Duration::from_nanos((seconds * 1_000_000_000f64) as u64);
}

/// keeps track of the passing of time from a recorded instant
pub struct Clock {
    reset_time: Cell<Instant>
}

impl Clock {

    /// create a new clock (starting from the moment it's created)
    pub fn new () -> Self {
        return Self { reset_time: Cell::new(Instant::now()) };
    }

    /// reset the clock back to its 0-state (no elapsed time)
    pub fn reset (&self) {
        self.reset_time.set(Instant::now());
    }

    /// get the elasped duration
    pub fn elapsed (&self) -> Duration {
        return Instant::now() - self.reset_time.get();
    }

    /// get the number of elapsed seconds as a 64-bit float
    pub fn elapsed_seconds (&self) -> f64 {
        return duration_to_seconds(self.elapsed());
    }

}

/// an object that provides a means of controlling the rate at which a loop is run
pub struct RevLimiter {

    /// whether or not each iteration advances by the same interval despite jitter (deterministic loops)
    pub lockstep_enabled: bool,

    /// whether or not the loop should attempt to catch up after incurring lag
    pub catchup_enabled: bool,

    /// the target duration between each iteration of the loop
    pub interval: Duration,

    /// a clock for keeping track of time elapsed since the last iteration
    pub clock: Clock,

    /// the duration of lag incurred behind the real-world elapsed time
    pub lag: Duration,

    /// the ratio of passing time in the loop to passing real time
    pub speed: f64,

}

impl RevLimiter {

    /// create a new rev limiter
    pub fn new (lockstep_enabled: bool, catchup_enabled: bool, interval_seconds: f64, speed: f64) -> Self {
        return Self {
            lockstep_enabled,
            catchup_enabled,
            interval: Duration::from_nanos((interval_seconds * 1_000_000_000f64) as u64),
            clock: Clock::new(),
            lag: Duration::new(0, 0),
            speed,
        };
    }

    /// create a new rev limiter given a custom clock


    /// create a new loop from a frequency (iterations per second) instead of an interval
    pub fn new_from_frequency (lockstep_enabled: bool, catchup_enabled: bool, per_second: u32, speed: f64) -> Self {
        return Self {
            lockstep_enabled,
            catchup_enabled,
            interval: Duration::from_nanos(((1.0 / (per_second as f64)) * 1_000_000_000.0) as u64),
            clock: Clock::new(),
            lag: Duration::new(0, 0),
            speed,
        };
    }

    /// call the callback, automatically calculating delta time
    fn get_delta (&self, current_elapsed: Duration) -> f64 {
        if self.lockstep_enabled {
            return duration_to_seconds(self.interval) * self.speed;
        }
        return duration_to_seconds(current_elapsed) * self.speed;
    }

    /// calculate a sleep duration after a loop iteration
    fn calculate_wait (
        current_elapsed: Duration,
        target_interval: Duration,
        current_lag: Duration
    ) -> Duration {
        if current_elapsed >= target_interval {
            return Duration::new(0, 0);
        } else {
            let delta = target_interval - current_elapsed;
            if current_lag > delta {
                return Duration::new(0, 0);
            } else {
                return delta - current_lag;
            }
        }
    }

    /// get the time to wait until the next loop iteration should run
    fn get_wait (&self, current_elapsed: Duration) -> Duration {
        Self::calculate_wait(current_elapsed, self.interval, self.lag)
    }

    /// calculate the remaining lag after a loop iteration
    fn calculate_lag (
        last_wait: Duration,
        target_interval: Duration,
        current_lag: Duration,
        catchup_enabled: bool
    ) -> Duration {
        if catchup_enabled {
            if last_wait >= target_interval {
                let lost_time = last_wait - target_interval;
                return current_lag + lost_time;
            } else {
                let gained_time = target_interval - last_wait;
                if current_lag > gained_time {
                    return current_lag - gained_time;
                } else {
                    return Duration::new(0, 0);
                }
            }
        } else {
            return Duration::new(0, 0);
        }
    }

    /// calculate and store the current lag of this loop
    fn update_lag (&mut self, current_wait: Duration) {
        self.lag = Self::calculate_lag(
            current_wait,
            self.interval,
            self.lag,
            self.catchup_enabled
        );
    }

    /// signal that execution for this iteration of the loop has started, mainly for the purpose of starting a timer
    pub fn begin (&mut self) -> f64 {
        let delta = self.get_delta(self.clock.elapsed());
        self.clock.reset();
        return delta;
    }

    /// signal that execution for this iteration of the loop has completed, and prepare for the next iteration
    pub fn next (&mut self) -> Duration {
        let wait = self.get_wait(self.clock.elapsed());
        self.clock.reset();
        self.update_lag(wait);
        return wait;
    }

    /// set the interval in seconds
    pub fn set_interval (&mut self, seconds: f64) {
        self.interval = Duration::from_nanos((seconds * 1_000_000_000.0) as u64);
    }

    /// set the frequency in iterations per second
    pub fn set_frequency (&mut self, per_second: u32) {
        self.interval = Duration::from_nanos(((1.0 / (per_second as f64)) * 1_000_000_000.0) as u64);
    }

}