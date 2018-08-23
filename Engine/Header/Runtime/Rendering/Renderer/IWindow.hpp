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

/// \file       IWindow.hpp
/// \date       30/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_I_WINDOW_HPP__
#define ORDINAL_ENGINE_I_WINDOW_HPP__

#include <string>
#include "Runtime/Platform/Configuration/Configuration.hpp"

/// \namespace ord
namespace Ord
{

/// \namespace rendering
namespace Rendering
{

/// \brief  Stores all required information to create a window
/// \struct SWindowCreateInfo
struct SWindowCreateInfo
{
    uint32_t    width;      ///< TODO
    uint32_t    height;     ///< TODO
    const char* p_name;     ///< TODO
};

/// \brief Interface for window
/// \class IWindow
class IWindow
{
public:

    /// \brief Initializes (open) a window
    /// \param window_create_info Create info structure
    virtual void Initialize(const SWindowCreateInfo& window_create_info) = 0;

    /// \brief Releases (close) the window
    virtual void Release() = 0;

    /// \brie Resizes the window
    virtual void Resize () = 0;

    /// \brief Updates the window
    virtual bool Update() = 0;

protected:

    /// \brief OS specific functions
    /// \see Window_win32
    void InitializeSurfaceOS();
    void InitializeOS       ();
    void ReleaseOS          ();
    void UpdateOS           ();

protected:

    bool        m_window_should_run = false; ///< TODO
    uint32_t    m_window_width      = 0;
    uint32_t    m_window_height     = 0;
    const char* mp_window_name      = nullptr;

private:

#ifdef ORDINAL_PLATFORM_WINDOWS
    HINSTANCE       m_win32_instance      = nullptr;
    HWND            m_win32_handle        = nullptr;
    std::string     m_win32_class_name;
    static uint64_t m_win32_class_counter;
#endif

};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_I_WINDOW_HPP__