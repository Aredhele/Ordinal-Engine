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

/// \file       CRenderingEngine.cpp
/// \date       23/05/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/CRenderingEngine.hpp"

/// \namespace ord
namespace ord
{

/// \brief Initializes the renderer
/// \return True on success, else false
bool CRenderingEngine::Initialize()
{
    // Window creation
    m_window.Initialize(1280, 720, "Ordinal Runtime");

    // Vulkan instance creation
    if(!m_vk_instance.CreateInstance())
    {
        SLogger::LogError("Unable to initialize the rendering engine.");
        return false;
    }

    SLogger::LogInfo("Rendering engine initialized");
    return true;
}

/// \brief Starts rendering
void CRenderingEngine::Run()
{
    GLFWwindow * p_window = m_window.GetContext();
    while (!glfwWindowShouldClose(p_window))
    {
        glfwPollEvents();
    }
}

} // !namespace