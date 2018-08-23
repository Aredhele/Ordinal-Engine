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

/// \file       COpenGL3Renderer.cpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Rendering/Renderer/OpenGL3/COpenGL3Renderer.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Initializes the renderer from the create info structure
/// \param s_renderer_info Contains all needed information to initialize a renderer
void COpenGL3Renderer::Initialize(const SRendererCreateInfo& s_renderer_info)
{
    // None
}

/// \brief Releases the renderer
void COpenGL3Renderer::Release()
{
    // None
}

/// \brief  Creates a window
/// \param  window_create_info The window create info
/// \return A pointer on the window
IWindow* COpenGL3Renderer::OpenWindow(const SWindowCreateInfo &window_create_info)
{
    return nullptr;
}

} // !namespace

} // !namespace
