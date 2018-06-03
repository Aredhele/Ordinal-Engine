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

/// \file       CRenderer.cpp
/// \date       03/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Rendering/CRenderer.hpp"

/// \namespace ord
namespace ord
{

/// \brief  Default constructor
CRenderer::CRenderer()
{
    // None
}

/// \brief  Destructor
CRenderer::~CRenderer()
{
    // None
}

/// \brief Initializes the renderer with an info structure
/// \param renderer_info The structure that contains info
///        about the renderer initialization
/// \throw Can throw runtime errors exceptions
void CRenderer::Initialize(const SRendererCreateInfo& renderer_info)
{
    throw std::runtime_error("Test error");
}

} // !namespace