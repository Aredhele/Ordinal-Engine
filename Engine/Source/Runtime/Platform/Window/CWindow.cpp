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
/// \date       09/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Window
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Platform/Window/CWindow.hpp"

/// \namespace ord
namespace ord
{

/// \namespace platform
namespace platform
{

/// \brief Destructor
CWindow::~CWindow()
{
    // TODO
}

/// \brief Initializes (open) a window
/// \param window_create_info Create info structure
void CWindow::Initialize(const SWindowCreateInfo &window_create_info)
{
    // TODO
}

/// \brief Releases (close) the window
void CWindow::Release()
{
    // TODO
}

/// \brief  Updates the window
/// \return True of false if the window is closed
bool CWindow::Update()
{
    return m_window_should_run;
}

} // !namespace

} // !namespace