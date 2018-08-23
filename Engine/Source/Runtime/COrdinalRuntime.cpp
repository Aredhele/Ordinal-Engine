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

/// \file       COrdinalRuntime.cpp
/// \date       29/06/2018
/// \project    Ordinal Engine
/// \package    Runtime
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/COrdinalRuntime.hpp"
#include "Runtime/Core/Debug/SLogger.hpp"

/// \namespace Ord
namespace Ord
{

/// \brief Destructor
COrdinalRuntime::~COrdinalRuntime()
{
    Release();
}

/// \brief Initializes the engine
void COrdinalRuntime::Initialize(const SOrdinalRuntimeCreateInfo& ordinal_runtime_create_info)
{
    Release();
    SLogger::LogInfo("Engine Initialization ...");

    mp_rendering_engine = Rendering::CRenderingEngine::GetInstance();
    mp_rendering_engine->Initialize(*ordinal_runtime_create_info.p_rendering_engine_create_info);

    m_initialized = true;
    SLogger::LogInfo("Engine fully initialized.\n");
}

/// \brief Starts the engine
void COrdinalRuntime::Run()
{
    bool b_should_run            = false;
    Rendering::IWindow* p_window = mp_rendering_engine->GetWindow();

    if(p_window)
    {
        b_should_run = p_window->Update();
    }
    else
    {
        b_should_run = false;
    }

    m_is_running = true;

    while(m_is_running && b_should_run)
    {
        b_should_run = mp_rendering_engine->Render();
    }
}

/// \brief Releases the engine
void COrdinalRuntime::Release()
{
    if(m_initialized)
    {
        SLogger::LogInfo("Releasing engine ...");

        mp_rendering_engine->Release();

        m_initialized = false;
        SLogger::LogInfo("Engine released.");
    }
}

} // !namespace