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

/// \file       CWindow_win32.cpp
/// \date       09/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Window
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Rendering/Window/CWindow.hpp"

/// \namespace ord
namespace ord
{

#ifdef VK_USE_PLATFORM_WIN32_KHR

/* static */ uint64_t CWindow::m_win32_class_id_counter = 0;

void CWindow::InitializeOSWindow()
{
    WNDCLASSEX win_class {};
}

void CWindow::UpdateOSWindow()
{

}

void CWindow::ReleaseOSWindow()
{

}

void CWindow::InitializeOSSurface()
{

}

#endif // !VK_USE_PLATFORM_WIN32_KHR

} // !namespace