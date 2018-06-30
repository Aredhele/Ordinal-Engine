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

/// \file       CWindow.hpp
/// \date       09/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Window
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_WINDOW_HPP__
#define ORDINAL_ENGINE_C_WINDOW_HPP__

#include <string>
#include "Runtime/Platform/Configuration/Configuration.hh"

/// \namespace ord
namespace ord
{

/// \namespace platform
namespace platform
{

/// \brief  Stores all required information to create a window
/// \struct SWindowCreateInfo
struct SWindowCreateInfo
{
    uint32_t    width;  ///< TODO
    uint32_t    height; ///< TODO
    const char* p_name; ///< TODO
};

/// \brief TODO
/// \class CWindow
class CWindow
{
public:

    /// \brief Destructor
    ~CWindow();

    /// \brief Opens a window
    /// \param window_create_info Create info structure
    void Open(const SWindowCreateInfo& window_create_info);

    /// \brief Closes the window
    void Close();

    /// \brief Updates the window
    bool Update();

private:

    void InitializeOSWindow();

    void ReleaseOSWindow();

    void UpdateOSWindow();

    void InitializeOSSurface();

private:

    bool m_window_should_run = true;  ///< TODO
};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_C_WINDOW_HPP__