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

/// \file       COpenGL3Renderer.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_OPEN_GL_3_RENDERER_HPP__
#define ORDINAL_ENGINE_C_OPEN_GL_3_RENDERER_HPP__

#include "Runtime/Rendering/Renderer/IRenderer.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief TODO
/// \class COpenGL3Renderer
class COpenGL3Renderer : public IRenderer
{
public:

    /// \brief Initializes the renderer from the create info structure
    /// \param s_renderer_info Contains all needed information to initialize a renderer
    void Initialize(const SRendererCreateInfo& s_renderer_info) final;

    /// \brief Releases the renderer
    void Release() final;

    /// \brief  Creates a window
    /// \param  window_create_info The window create info
    /// \return A pointer on the window
    IWindow* OpenWindow(const SWindowCreateInfo& window_create_info) final;
};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_C_OPEN_GL_3_RENDERER_HPP__