/// Copyright (C) 2018-2019, Ordinal Engine
/// Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
///
/// This program is free software; you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation; either version 2 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License along
/// with this program; if not, write to the Free Software Foundation, Inc.,
/// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

/// \file       IRenderer.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_I_RENDERER_HPP__
#define ORDINAL_ENGINE_I_RENDERER_HPP__

#include "Runtime/Rendering/Renderer/IWindow.hpp"

/// \namespace ord
namespace Ord
{

/// \namespace rendering
namespace Rendering
{

/// \brief Represents the rendering api to use
/// \enum  ERenderingAPI
enum ERenderingAPI
{
    RENDERING_API_AUTO        = 0, ///< The engine chooses the most appropriate rendering api
    RENDERING_API_VULKAN      = 1, ///< The engine try to use Vulkan
    RENDERING_API_OPENGL_3    = 2, ///< The engine try to use OpenGL 3
    RENDERING_API_OPENGL_4    = 3, ///< The engine try to use OpenGL 4
    RENDERING_API_DIRECT3D_12 = 4  ///< The engine try to use Direct3D 12
};

/// \brief  Contains all needed information to initialize the renderer
/// \struct SRendererCreateInfo
struct SRendererCreateInfo
{
    const char* p_engine_name;          ///< The name of the engine
    const char* p_application_name;     ///< The name of the application
    uint32_t    api_version;            ///< The version of the vulkan api
    uint32_t    engine_version;         ///< The version of the engine
    uint32_t    application_version;    ///< The version of the application
};

/// \brief Base interface for all renderers
/// \class IRenderer
class IRenderer
{
public:

    /// \brief Initializes the renderer from the create info structure
    /// \param renderer_info Contains all needed information to initialize a renderer
    virtual void Initialize(const SRendererCreateInfo& renderer_info) = 0;

    /// \brief Releases the renderer
    virtual void Release() = 0;

    /// \brief  Creates a window
    /// \param  window_create_info The window create info
    /// \return A pointer on the window
    virtual IWindow* OpenWindow(const SWindowCreateInfo& window_create_info) = 0;
};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_I_RENDERER_HPP__