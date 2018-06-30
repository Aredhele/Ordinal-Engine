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

#include <stdexcept>

#include "Runtime/COrdinalRuntime.hpp"
#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Platform/Configuration/Configuration.hh"

using COrdinalRuntime            = ord::COrdinalRuntime;
using SOrdinalRuntimeCreateInfo  = ord::SOrdinalRuntimeCreateInfo;
using SRendererCreateInfo        = ord::rendering::SRendererCreateInfo;
using SRenderingEngineCreateInfo = ord::rendering::SRenderingEngineCreateInfo;

/// \brief Ordinal engine entry points
int Ordinal_EntryPoint(int argc, char ** argv)
{
    // Engine
    COrdinalRuntime ordinal_runtime;

    SRendererCreateInfo renderer_create_info {};
    {
        renderer_create_info.p_engine_name         = "Ordinal Engine";
        renderer_create_info.p_application_name    = "Ordinal";
        renderer_create_info.api_version           = (1 << 22) | (1 << 12) | 0;
        renderer_create_info.engine_version        = (0 << 22) | (1 << 12) | 0;
        renderer_create_info.application_version   = (0 << 22) | (1 << 12) | 0;
    }

    SRenderingEngineCreateInfo rendering_engine_create_info {};
    {
        rendering_engine_create_info.e_rendering_api        = ord::rendering::RENDERING_API_VULKAN;
        rendering_engine_create_info.p_renderer_create_info = &renderer_create_info;
    }

    SOrdinalRuntimeCreateInfo runtime_create_info {};
    {
        runtime_create_info.p_runtime_name                 = "Ordinal Runtime";
        runtime_create_info.runtime_version                = (0 << 22) | (0 << 12) | 1;
        runtime_create_info.p_rendering_engine_create_info = &rendering_engine_create_info;
    }

    try
    {
        ordinal_runtime.Initialize(runtime_create_info);
        ordinal_runtime.Run();
        ordinal_runtime.Release();
    }
    catch (const std::runtime_error& error)
    {
        ord::SLogger::LogError("Caught : %s.", error.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}