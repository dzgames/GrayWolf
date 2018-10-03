#include "../../../../include/TimberWolf/Graphics/OpenGL/GLShaderStore.hpp"

/**
 * @class tw::GLShaderStore
 *
 * Static map-based object cache keeping track of handles to shader objects and
 * shader programs via a std::string key.
 */

/**
 * Check if a vertex shader handle with the given key exists.
 *
 * @param key vertex shader key to check
 * @return true if vertex shader key exists, false if not
 */
bool tw::GLShaderStore::vertexShaderExists (const std::string& key) {

    if (m_vertexShaders.find(key) == m_vertexShaders.end()) {
        return false;
    } else {
        return true;
    }

}

/**
 * Get a std::shared_ptr to the vertex shader handle with the given key. Returns
 * nullptr if the vertex shader key does not exist.
 *
 * @param key vertex shader key
 * @return shared pointer to vertex shader handle, nullptr if none
 */
std::shared_ptr<tw::GLVertexShader> tw::GLShaderStore::getVertexShader (const std::string& key) {

    if (!vertexShaderExists(key)) {
        return nullptr;
    }

    return m_vertexShaders[key];

}

/**
 * Check if a fragment shader handle with the given key exists.
 *
 * @param key fragment shader key to check
 * @return true if fragment shader key exists, false if not
 */
bool tw::GLShaderStore::fragmentShaderExists (const std::string& key) {

    if (m_fragmentShaders.find(key) == m_fragmentShaders.end()) {
        return false;
    } else {
        return true;
    }

}

/**
 * Get a std::shared_ptr to the fragment shader handle with the given key.
 * Returns nullptr if the fragment shader key does not exist.
 *
 * @param key fragment shader key
 * @return shared pointer to fragment shader handle, nullptr if none
 */
std::shared_ptr<tw::GLFragmentShader> tw::GLShaderStore::getFragmentShader (const std::string& key) {

    if (!fragmentShaderExists(key)) {
        return nullptr;
    }

    return m_fragmentShaders[key];

}

/**
 * Check if a geometry shader handle with the given key exists.
 *
 * @param key geometry shader key to check
 * @return true if geometry shader key exists, false if not
 */
bool tw::GLShaderStore::geometryShaderExists (const std::string& key) {

    if (m_geometryShaders.find(key) == m_geometryShaders.end()) {
        return false;
    } else {
        return true;
    }

}

/**
 * Get a std::shared_ptr to the geometry shader handle with the given key.
 * Returns nullptr if the geometry shader key does not exist.
 *
 * @param key geometry shader key
 * @return shared pointer to geometry shader, nullptr if none
 */
std::shared_ptr<tw::GLGeometryShader> tw::GLShaderStore::getGeometryShader (const std::string& key) {

    if (!geometryShaderExists(key)) {
        return nullptr;
    }

    return m_geometryShaders[key];

}

/**
 * Check if a tesselation evaluation shader handle with the given key exists.
 *
 * @param key tesselation evaluation shader key to check
 * @return true if tesselation evaluation shader key exists, false if not
 */
bool tw::GLShaderStore::tesselationEvaluationShaderExists (const std::string& key) {

    if (m_tesselationEvaluationShaders.find(key) == m_tesselationEvaluationShaders.end()) {
        return false;
    } else {
        return true;
    }

}

/**
 * Get a std::shared_ptr to the tesselation evaluation shader handle with the
 * given key. Returns nullptr if the tesselation evaluation shader key does not
 * exist.
 *
 * @param key tesselation evaluation shader key
 * @return shared pointer to tesselation evaluation shader, nullptr if none
 */
std::shared_ptr<tw::GLTesselationEvaluationShader> tw::GLShaderStore::getTesselationEvaluationShader (const std::string& key) {

    if (!tesselationEvaluationShaderExists(key)) {
        return nullptr;
    }

    return m_tesselationEvaluationShaders[key];

}

/**
 * Check if a tesselation control shader handle with the given key exists.
 *
 * @param key tesselation control shader key to check
 * @return true if tesselation control shader key exists, false if not
 */
bool tw::GLShaderStore::tesselationControlShaderExists (const std::string& key) {

    if (m_tesselationControlShaders.find(key) == m_tesselationControlShaders.end()) {
        return false;
    } else {
        return true;
    }

}

/**
 * Get a std::shared_ptr to the tesselation control shader handle with the given
 * key. Returns nullptr if the tesselation control shader key does not exist.
 *
 * @param key tesselation evaluation shader key
 * @return shared pointer to tesselation control shader, nullptr if none
 */
std::shared_ptr<tw::GLTesselationControlShader> tw::GLShaderStore::getTesselationControlShader (const std::string& key) {

    if (!tesselationControlShaderExists(key)) {
        return nullptr;
    }

    return m_tesselationControlShaders[key];

}

/**
 * Check if a compute shader handle with the given key exists.
 *
 * @param key compute shader key to check
 * @return true if compute shader key exists, false if not
 */
bool tw::GLShaderStore::computeShaderExists (const std::string& key) {

    if (m_computeShaders.find(key) == m_computeShaders.end()) {
        return false;
    } else {
        return true;
    }

}

/**
 * Get a std::shared_ptr to the compute shader handle with the given key.
 * Returns nullptr if the compute shader key does not exist.
 *
 * @param key compute shader key
 * @return shared pointer to compute shader, nullptr if none
 */
std::shared_ptr<tw::GLComputeShader> tw::GLShaderStore::getComputeShader (const std::string& key) {

    if (!computeShaderExists(key)) {
        return nullptr;
    }

    return m_computeShaders[key];

}

/**
 * Check if a shader program handle with the given key exists.
 *
 * @param key shader program key to checl
 * @return true if shader program key exists, false if not
 */
bool tw::GLShaderStore::shaderProgramExists (const std::string& key) {

    if (m_shaderPrograms.find(key) == m_shaderPrograms.end()) {
        return false;
    } else {
        return true;
    }

}

/**
 * Get a std::shared_ptr to the shader program handle with the given key.
 * Returns nullptr if the shader program key does not exist.
 *
 * @param key shader program key
 * @return shared pointer to shader program, nullptr if none
 */
std::shared_ptr<tw::GLShaderProgram> tw::GLShaderStore::getShaderProgram (const std::string& key) {

    if (!shaderProgramExists(key)) {
        return nullptr;
    }

    return m_shaderPrograms[key];

}

/**
 * @fn tw::GLShaderStore::makeVertexShader
 *
 * Factory method that creates a vertex shader using the given arguments, and
 * then stores the new std::shared_ptr to the vertex shader handle in the cache
 * under the given std::string key.
 *
 * @tparam T    variadic types of arguments forwarded to tw::GLVertexShader contructor (automatically deduced)
 * @param  key  vertex shader key
 * @param  args variadic arguments forwarded to tw::GLVertexShader constructor
 * @return shared pointer to the created vertex shader handle
 */

/**
 * Store a given std::shared_ptr to a vertex shader handle in the cache under
 * the given std::string key.
 *
 * @param key          vertex shader key
 * @param vertexShader shared pointer to vertex shader handle
 * @return true if vertex shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerVertexShader (const std::string& key, const std::shared_ptr<GLVertexShader>& vertexShader) {

    if (vertexShaderExists(key)) {
        logVertexShaderAlreadyExists(key);
        return false;
    }

    m_vertexShaders.emplace(key, vertexShader);
    return true;

}

/**
 * Store a given pointer to a vertex shader handle in the cache under the given
 * std::string key. Note that even though this takes in a normal pointer, the
 * vertex shader handle will be stored as a std::shared_ptr and will be deleted
 * if removed from the cache.
 *
 * @param key          vertex shader key
 * @param vertexShader pointer to vertex shader handle
 * @return true if vertex shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerVertexShader (const std::string& key, GLVertexShader* vertexShader) {

    return registerVertexShader(key, std::shared_ptr<GLVertexShader>(vertexShader));

}

/**
 * Remove the vertex shader handle with the given std::string key from the
 * cache. The vertex shader will be deleted when the final surviving reference
 * falls out of scope.
 *
 * @param key vertex shader key
 */
void tw::GLShaderStore::deleteVertexShader (const std::string& key) {

    if (!vertexShaderExists(key)) {
        return;
    }

    m_vertexShaders[key].reset();
    m_vertexShaders.erase(key);

}

/**
 * @fn tw::GLShaderStore::makeFragmentShader
 *
 * Factory method that creates a fragment shader using the given arguments, and
 * then stores the new std::shared_ptr to the fragment shader handle in the
 * cache under the given std::string key.
 *
 * @tparam T    variadic types of arguments forwarded to tw::GLFragmentShader contructor (automatically deduced)
 * @param  key  fragment shader key
 * @param  args variadic arguments forwarded to tw::GLFragmentShader constructor
 * @return shared pointer to the created fragment shader handle
 */

/**
 * Store a given std::shared_ptr to a fragment shader handle in the cache under
 * the given std::string key.
 *
 * @param key            fragment shader key
 * @param fragmentShader shared pointer to fragment shader handle
 * @return true if fragment shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerFragmentShader (const std::string& key, const std::shared_ptr<GLFragmentShader>& fragmentShader) {

    if (fragmentShaderExists(key)) {
        logFragmentShaderAlreadyExists(key);
        return false;
    }

    m_fragmentShaders.emplace(key, fragmentShader);
    return true;

}

/**
 * Store a given pointer to a fragment shader handle in the cache under the
 * given std::string key. Note that even though this takes in a normal pointer,
 * the fragment shader handle will be stored as a std::shared_ptr and will be
 * deleted if removed from the cache.
 *
 * @param key            fragment shader key
 * @param fragmentShader pointer to fragment shader handle
 * @return true if fragment shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerFragmentShader (const std::string& key, GLFragmentShader* fragmentShader) {

    return registerFragmentShader(key, std::shared_ptr<GLFragmentShader>(fragmentShader));

}

/**
 * Remove the fragment shader handle with the given std::string key from the
 * cache. The fragment shader will be deleted when the final surviving reference
 * falls out of scope.
 *
 * @param key fragment shader key
 */
void tw::GLShaderStore::deleteFragmentShader (const std::string& key) {

    if (!fragmentShaderExists(key)) {
        return;
    }

    m_fragmentShaders[key].reset();
    m_fragmentShaders.erase(key);

}

/**
 * @fn tw::GLShaderStore::makeGeometryShader
 *
 * Factory method that creates a geometry shader using the given arguments, and
 * then stores the new std::shared_ptr to the geometry shader handle in the
 * cache under the given std::string key.
 *
 * @tparam T    variadic types of arguments forwarded to tw::GLGeometryShader contructor (automatically deduced)
 * @param  key  geometry shader key
 * @param  args variadic arguments forwarded to tw::GLGeometryShader constructor
 * @return shared pointer to the created geometry shader handle
 */

/**
 * Store a given std::shared_ptr to a geometry shader handle in the cache under
 * the given std::string key.
 *
 * @param key            geometry shader key
 * @param geometryShader shared pointer to geometry shader handle
 * @return true if geometry shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerGeometryShader (const std::string& key, const std::shared_ptr<GLGeometryShader>& geometryShader) {

    if (geometryShaderExists(key)) {
        logGeometryShaderAlreadyExists(key);
        return false;
    }

    m_geometryShaders.emplace(key, geometryShader);
    return true;

}

/**
 * Store a given pointer to a geometry shader handle in the cache under the
 * given std::string key. Note that even though this takes in a normal pointer,
 * the geometry shader handle will be stored as a std::shared_ptr and will be
 * deleted if removed from the cache.
 *
 * @param key            geometry shader key
 * @param geometryShader pointer to geometry shader handle
 * @return true if geometry shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerGeometryShader (const std::string& key, GLGeometryShader* geometryShader) {

    return registerGeometryShader(key, std::shared_ptr<GLGeometryShader>(geometryShader));

}

/**
 * Remove the geometry shader handle with the given std::string key from the
 * cache. The geometry shader will be deleted when the final surviving reference
 * falls out of scope.
 *
 * @param key geometry shader key
 */
void tw::GLShaderStore::deleteGeometryShader (const std::string& key) {

    if (!geometryShaderExists(key)) {
        return;
    }

    m_geometryShaders[key].reset();
    m_geometryShaders.erase(key);

}

/**
 * @fn tw::GLShaderStore::makeTesselationEvaluationShader
 *
 * Factory method that creates a tesselation evaluation shader using the given
 * arguments, and then stores the new std::shared_ptr to the tesselation
 * evaluation shader handle in the cache under the given std::string key.
 *
 * @tparam T    variadic types of arguments forwarded to tw::GLTesselationEvaluationShader contructor (automatically deduced)
 * @param  key  tesselation evaluation shader key
 * @param  args variadic arguments forwarded to tw::GLTesselationEvaluationShader constructor
 * @return shared pointer to the created tesselation evaluation shader handle
 */

/**
 * Store a given std::shared_ptr to a tesselation evaluation shader handle in
 * the cache under the given std::string key.
 *
 * @param key                         tesselation evaluation shader key
 * @param tesselationEvaluationShader shared pointer to tesselation evaluation shader handle
 * @return true if tesselation evaluation shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerTesselationEvaluationShader (const std::string& key, const std::shared_ptr<GLTesselationEvaluationShader>& tesselationEvaluationShader) {

    if (tesselationEvaluationShaderExists(key)) {
        logTesselationEvaluationShaderAlreadyExists(key);
        return false;
    }

    m_tesselationEvaluationShaders.emplace(key, tesselationEvaluationShader);
    return true;

}

/**
 * Store a given pointer to a tesselation evaluation shader handle in the cache
 * under the given std::string key. Note that even though this takes in a normal
 * pointer, the tesselation evaluation shader handle will be stored as a
 * std::shared_ptr and will be deleted if removed from the cache.
 *
 * @param key                         tesselation evaluation shader key
 * @param tesselationEvaluationShader pointer to tesselation evaluation shader handle
 * @return true if tesselation evaluation shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerTesselationEvaluationShader (const std::string& key, GLTesselationEvaluationShader* tesselationEvaluationShader) {

    return registerTesselationEvaluationShader(key, std::shared_ptr<GLTesselationEvaluationShader>(tesselationEvaluationShader));

}

/**
 * Remove the tesselation evaluation shader handle with the given std::string
 * key from the cache. The tesselation evaluation shader will be deleted when
 * the final surviving reference falls out of scope.
 *
 * @param key tesselation evaluation shader key
 */
void tw::GLShaderStore::deleteTesselationEvaluationShader (const std::string& key) {

    if (!tesselationEvaluationShaderExists(key)) {
        return;
    }

    m_tesselationEvaluationShaders[key].reset();
    m_tesselationEvaluationShaders.erase(key);

}

/**
 * @fn tw::GLShaderStore::makeTesselationControlShader
 *
 * Factory method that creates a tesselation control shader using the given
 * arguments, and then stores the new std::shared_ptr to the tesselation control
 * shader handle in the cache under the given std::string key.
 *
 * @tparam T    variadic types of arguments forwarded to tw::GLTesselationControlShader contructor (automatically deduced)
 * @param  key  tesselation control shader key
 * @param  args variadic arguments forwarded to tw::GLTesselationControlShader constructor
 * @return shared pointer to the created tesselation control shader handle
 */

/**
 * Store a given std::shared_ptr to a tesselation control shader handle in the
 * cache under the given std::string key.
 *
 * @param key                      tesselation control shader key
 * @param tesselationControlShader shared pointer to tesselation control shader handle
 * @return true if tesselation control shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerTesselationControlShader (const std::string& key, const std::shared_ptr<GLTesselationControlShader>& tesselationControlShader) {

    if (tesselationControlShaderExists(key)) {
        logTesselationControlShaderAlreadyExists(key);
        return false;
    }

    m_tesselationControlShaders.emplace(key, tesselationControlShader);
    return true;

}

/**
 * Store a given pointer to a tesselation control shader handle in the cache
 * under the given std::string key. Note that even though this takes in a normal
 * pointer, the tesselation control shader handle will be stored as a
 * std::shared_ptr and will be deleted if removed from the cache.
 *
 * @param key                      tesselation control shader key
 * @param tesselationControlShader pointer to tesselation shader handle
 * @return true if tesselation control shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerTesselationControlShader (const std::string& key, GLTesselationControlShader* tesselationControlShader) {

    return registerTesselationControlShader(key, std::shared_ptr<GLTesselationControlShader>(tesselationControlShader));

}

/**
 * Remove the tesselation control shader handle with the given std::string key
 * from the cache. The tesselation control shader will be deleted when the final
 * surviving reference falls out of scope.
 *
 * @param key tesselation control shader key
 */
void tw::GLShaderStore::deleteTesselationControlShader (const std::string& key) {

    if (!tesselationControlShaderExists(key)) {
        return;
    }

    m_tesselationControlShaders[key].reset();
    m_tesselationControlShaders.erase(key);

}

/**
 * @fn tw::GLShaderStore::makeComputeShader
 *
 * Factory method that creates a compute shader using the given arguments, and
 * then stores the new std::shared_ptr to the compute shader handle in the cache
 * under the given std::string key.
 *
 * @tparam T    variadic types of arguments forwarded to tw::GLComputeShader contructor (automatically deduced)
 * @param  key  compute shader key
 * @param  args variadic arguments forwarded to tw::GLComputeShader constructor
 * @return shared pointer to the created compute shader handle
 */

/**
 * Store a given std::shared_ptr to a compute shader handle in the cache under
 * the given std::string key.
 *
 * @param key           compute shader key
 * @param computeShader shared pointer to compute shader handle
 * @return true if compute shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerComputeShader (const std::string& key, const std::shared_ptr<GLComputeShader>& computeShader) {

    if (computeShaderExists(key)) {
        logComputeShaderAlreadyExists(key);
        return false;
    }

    m_computeShaders.emplace(key, computeShader);
    return true;

}

/**
 * Store a given pointer to a compute shader handle in the cache under the
 * given std::string key. Note that even though this takes in a normal pointer,
 * the compute shader handle will be stored as a std::shared_ptr and will be
 * deleted if removed from the cache.
 *
 * @param key           compute shader key
 * @param computeShader pointer to fragment shader handle
 * @return true if compute shader was successfully registered, false if not
 */
bool tw::GLShaderStore::registerComputeShader (const std::string& key, GLComputeShader* computeShader) {

    return registerComputeShader(key, std::shared_ptr<GLComputeShader>(computeShader));

}

/**
 * Remove the compute shader handle with the given std::string key from the
 * cache. The compute shader will be deleted when the final surviving reference
 * falls out of scope.
 *
 * @param key compute shader key
 */
void tw::GLShaderStore::deleteComputeShader (const std::string& key) {

    if (!computeShaderExists(key)) {
        return;
    }

    m_computeShaders[key].reset();
    m_computeShaders.erase(key);

}

/**
 * @fn tw::GLShaderStore::makeShaderProgram
 *
 * Factory method that creates a shader program using the given arguments, and
 * then stores the new std::shared_ptr to the shader program handle in the cache
 * under the given std::string key.
 *
 * @tparam T    variadic types of arguments forwarded to tw::ShaderProgram contructor (automatically deduced)
 * @param  key  shader program key
 * @param  args variadic arguments forwarded to tw::ShaderProgram constructor
 * @return shared pointer to the created shader program handle
 */

/**
 * Store a given std::shared_ptr to a shader program handle in the cache under
 * the given std::string key.
 *
 * @param key           shader program key
 * @param shaderProgram shared pointer to shader program handle
 * @return true if shader program was successfully registered, false if not
 */
bool tw::GLShaderStore::registerShaderProgram (const std::string& key, const std::shared_ptr<GLShaderProgram>& shaderProgram) {

    if (shaderProgramExists(key)) {
        logShaderProgramAlreadyExists(key);
        return false;
    }

    m_shaderPrograms.emplace(key, shaderProgram);
    return true;

}

/**
 * Store a given pointer to a shader program handle in the cache under the given
 * std::string key. Note that even though this takes in a normal pointer, the
 * shader program handle will be stored as a std::shared_ptr and will be deleted
 * if removed from the cache.
 *
 * @param key           shader program key
 * @param shaderProgram pointer to shader program handle
 * @return true if shader program was successfully registered, false if not
 */
bool tw::GLShaderStore::registerShaderProgram (const std::string& key, GLShaderProgram* shaderProgram) {

    return registerShaderProgram(key, std::shared_ptr<GLShaderProgram>(shaderProgram));

}

/**
 * Remove the shader program handle with the given std::string key from the
 * cache. The shader program will be deleted when the final surviving reference
 * falls out of scope.
 *
 * @param key shader program key
 */
void tw::GLShaderStore::deleteShaderProgram (const std::string& key) {

    if (!shaderProgramExists(key)) {
        return;
    }

    m_shaderPrograms[key].reset();
    m_shaderPrograms.erase(key);

}

/**
 * Send a log message indicating that a vertex shader registration failed due to
 * another vertex shader with the given key already having been registered.
 *
 * @param key vertex shader key
 */
void tw::GLShaderStore::logVertexShaderAlreadyExists (const std::string& key) {

    Log::warning("shaderstore", "Vertex shader with \"", key, "\" key already exists.");

}

/**
 * Send a log message indicating that a fragment shader registration failed due
 * to another fragment shader with the given key already having been registered.
 *
 * @param key fragment shader key
 */
void tw::GLShaderStore::logFragmentShaderAlreadyExists (const std::string& key) {

    Log::warning("shaderstore", "Fragment shader with \"", key, "\" key already exists.");

}

/**
 * Send a log message indicating that a geometry shader registration failed due
 * to another geometry shader with the given key already having been registered.
 *
 * @param key geometry shader key
 */
void tw::GLShaderStore::logGeometryShaderAlreadyExists (const std::string& key) {

    Log::warning("shaderstore", "Geometry shader with \"", key, "\" key already exists.");

}

/**
 * Send a log message indicating that a tesselation evaluation shader
 * registration failed due to another tesselation evaluation shader with the
 * given key already having been registered.
 *
 * @param key tesselation evaluation shader key
 */
void tw::GLShaderStore::logTesselationEvaluationShaderAlreadyExists (const std::string& key) {

    Log::warning("shaderstore", "Tesselation evaluation shader with \"", key, "\" key already exists.");

}

/**
 * Send a log message indicating that a tesselation control shader registration
 * failed due to another tesselation control shader with the given key already
 * having been registered.
 *
 * @param key tesselation control shader key
 */
void tw::GLShaderStore::logTesselationControlShaderAlreadyExists (const std::string& key) {

    Log::warning("shaderstore", "Tesselation control shader with \"", key, "\" key already exists.");

}

/**
 * Send a log message indicating that a compute shader registration failed due
 * to another compute shader with the given key already having been registered.
 *
 * @param key compute shader key
 */
void tw::GLShaderStore::logComputeShaderAlreadyExists (const std::string& key) {

    Log::warning("shaderstore", "Compute shader with \"", key, "\" key already exists.");

}

/**
 * Send a log message indicating that a shader program registration failed due
 * to another shader program with the given key already having been registered.
 *
 * @param key shader program key
 */
void tw::GLShaderStore::logShaderProgramAlreadyExists (const std::string& key) {

    Log::warning("shaderstore", "Shader program with \"", key, "\" key already exists.");

}

std::unordered_map<std::string, std::shared_ptr<tw::GLVertexShader>> tw::GLShaderStore::m_vertexShaders; ///< vertex shader cache
std::unordered_map<std::string, std::shared_ptr<tw::GLFragmentShader>> tw::GLShaderStore::m_fragmentShaders; ///< fragment shader cache
std::unordered_map<std::string, std::shared_ptr<tw::GLGeometryShader>> tw::GLShaderStore::m_geometryShaders; ///< geometry shader cache
std::unordered_map<std::string, std::shared_ptr<tw::GLTesselationEvaluationShader>> tw::GLShaderStore::m_tesselationEvaluationShaders; ///< tesselation evaluation shader cache
std::unordered_map<std::string, std::shared_ptr<tw::GLTesselationControlShader>> tw::GLShaderStore::m_tesselationControlShaders; ///< tesselation control shader cache
std::unordered_map<std::string, std::shared_ptr<tw::GLComputeShader>> tw::GLShaderStore::m_computeShaders; ///< compute shader cache

std::unordered_map<std::string, std::shared_ptr<tw::GLShaderProgram>> tw::GLShaderStore::m_shaderPrograms; ///< shader program cache
