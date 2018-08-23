/// Copyright (C) 2018-2019, Ordinal Engine
/// Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
/// See https://vincentcalisto.com/ordinal-engine/
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

/// \file       CVulkanWindow.cpp
/// \date       23/08/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Rendering/Renderer/Vulkan/CVulkanWindow.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Initializes (open) a window
/// \param window_create_info Create info structure
void CVulkanWindow::Initialize(const SWindowCreateInfo& window_create_info)
{
    m_window_width  = window_create_info.width;
    m_window_height = window_create_info.height;
    mp_window_name  = window_create_info.p_name;

    InitializeOS();
    m_window_should_run = true;
}

/// \brief Releases (close) the window
void CVulkanWindow::Release()
{
    ReleaseOS();
    m_window_should_run = false;
}

/// \brief Updates the window
bool CVulkanWindow::Update()
{
    UpdateOS();
    return m_window_should_run;
}

/// \brief Resizes the window
void CVulkanWindow::Resize()
{
    // TODO
}

} // !namespace

} // !namespace


