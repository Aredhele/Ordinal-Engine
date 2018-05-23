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

/// \file       CWindow.cpp
/// \date       23/05/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Window/
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Core/Assertion/Assert.hh"
#include "Runtime/Rendering/Window/CWindow.hpp"

/// \namespace ord
namespace ord
{

/// \brief  Destructor
CWindow::~CWindow()
{
    Destroy();
}

/// \brief  Initializes the OpenGL context
/// \param  width The width of the window
/// \param  height The heigth of the window
/// \param  sz_title The title of the window
void CWindow::Initialize(int width, int height, const char * sz_title)
{
    // Pre-conditions
    ASSERT_GT(width,  0);
    ASSERT_GT(height, 0);

    if(mp_window != nullptr)
    {
        Destroy();
    }

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE,  GLFW_FALSE);

    mp_window = glfwCreateWindow(width, height, sz_title, nullptr, nullptr);
    if(mp_window == nullptr)
    {
        SLogger::LogError(
                "Unable to create the vulkan window context."
                "Is your hardware compatible ?");

        glfwTerminate();
        return;
    }

    SLogger::LogInfo("Context successfully initialized.");

    // Post-conditions
    ASSERT_NOT_NULL(mp_window);
}

/// \brief  Returns the current glfw window
/// \return A pointer on the glfw window
GLFWwindow * CWindow::GetContext() const
{
    return mp_window;
}

/// \brief Destroy the current OpenGL context
void CWindow::Destroy()
{
    if(mp_window != nullptr)
    {
        glfwDestroyWindow(mp_window);
        glfwTerminate();
    }
}

} // !namespace