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

/// \file       CWindow.hpp
/// \date       23/05/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Window/
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_WINDOW_HPP__
#define ORDINAL_ENGINE_C_WINDOW_HPP__

#include "Glfw/glfw3.h"

/// \namespace ord
namespace ord
{

/// \brief Manages GLFW window
/// \class CWindow
class CWindow
{
public:

    /// \brief Default constructor
    explicit CWindow();

    /// \brief  Constructor
    /// \param  width The width of the window
    /// \param  height The heigth of the window
    /// \param  sz_title The title of the window
    explicit CWindow(int width, int height, const char * sz_title);

    /// \brief  Destructor
    ~CWindow();

    /// \brief  Initializes the OpenGL context
    /// \param  width The width of the window
    /// \param  height The heigth of the window
    /// \param  sz_title The title of the window
    void Initialize(int width, int height, const char * sz_title);

    /// \brief  Returns the current glfw window
    /// \return A pointer on the glfw window
    GLFWwindow * GetContext() const;

private:

    /// \brief Destroy the current OpenGL context
    void Destroy();

private:

    GLFWwindow * mp_window = nullptr; ///< The window pointer
};

} // !namespace

#endif // !ORDINAL_ENGINE_C_WINDOW_HPP__