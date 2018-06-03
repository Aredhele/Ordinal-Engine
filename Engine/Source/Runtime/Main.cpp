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

/// \file       Main.cpp
/// \date       23/05/2018
/// \project    Ordinal Engine
/// \package    Runtime
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/CRenderer.hpp"
#include "Runtime/Platform/Configuration/Configuration.hh"

/// \brief Ordinal engine entry points
int Ordinal_EntryPoint(int argc, char ** argv)
{
    // Information about the window
    ord::SWindowCreateInfo s_window_create_info {};
    s_window_create_info.window_width    = 1280;
    s_window_create_info.window_height   = 720;
    s_window_create_info.p_window_name   = "Ordinal Engine";

    // Information about the renderer
    ord::SRendererCreateInfo s_renderer_create_info {};
    s_renderer_create_info.p_engine_name         = "Ordinal Engine";
    s_renderer_create_info.p_application_name    = "Ordinal";
    s_renderer_create_info.p_window_info         = s_window_create_info;
    s_renderer_create_info.api_version           = VK_MAKE_VERSION(1, 1, 0);
    s_renderer_create_info.engine_version        = VK_MAKE_VERSION(0, 1, 0);
    s_renderer_create_info.application_version   = VK_MAKE_VERSION(0, 1, 0);

    ord::CRenderer renderer;

    try
    {
        // Tries to initialize the renderer
        renderer.Initialize(s_renderer_create_info);
    }
    catch (const std::runtime_error& error)
    {
        // Something wrong happened
        ord::SLogger::LogError(error.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}