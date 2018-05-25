#ifndef H_PKG_TW_GRAPHICS
#define H_PKG_TW_GRAPHICS

/**
 * @file
 *
 * Auto-include header for the graphics subsystem. Represents the headers that
 * are applicable to the graphics rendering subsystem, not including the
 * graphics API backends themselves, which are separate packages. The headers
 * included in the graphics package may reference the core, log, and window
 * packages.
 */

#include "Core.hpp"
#include "Log.hpp"
#include "Window.hpp"

#include "Graphics/GLBufferable.hpp"
#include "Graphics/Mesh.hpp"
#include "Graphics/Model.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/Scene.hpp"
#include "Graphics/TexturePoint.hpp"
#include "Graphics/Vertex.hpp"
#include "Graphics/VertexCollection.hpp"

#endif