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

/// \file       CRenderingEngine.cpp
/// \date       29/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/CRenderingEngine.hpp"
#include "Runtime/Rendering/Renderer/Renderers.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief Private constructor
CRenderingEngine::CRenderingEngine()
{
    // TODO
}

/// \brief Private destructor
CRenderingEngine::~CRenderingEngine()
{
    Release();
}

/// \brief  Creates an instance of the Rendering engine
/// \return The instance of the rendering engine
/* static */ CRenderingEngine* CRenderingEngine::GetInstance()
{
    static CRenderingEngine rendering_engine;
    return &rendering_engine;
}

/// \brief Initializes the rendering engine
/// \param rendering_engine_create_info The info to create the rendering engine
void CRenderingEngine::Initialize(const SRenderingEngineCreateInfo &rendering_engine_create_info)
{
    SLogger::LogInfo("Rendering engine initialization ...");

    InitializeRenderer(rendering_engine_create_info);

    SLogger::LogInfo("Rendering engine fully initialized;");
}

/// \brief Releases the rendering engine
void CRenderingEngine::Release()
{
    // TODO
}

/// \brief Initializes the renderer
/// \param rendering_engine_create_info The info to create the rendering engine
void CRenderingEngine::InitializeRenderer(const SRenderingEngineCreateInfo &rendering_engine_create_info)
{
    SLogger::LogInfo("  Initializing renderer.");

    if(!mp_renderer != nullptr)
    {
        mp_renderer->Release();
        delete mp_renderer;
        mp_renderer = nullptr;
    }

    // Instantiating the renderer
    switch(rendering_engine_create_info.e_renderering_api)
    {
        // TODO : Implements auto selection
        case RENDERING_API_AUTO:        mp_renderer = new CVulkanRenderer();     break;
        case RENDERING_API_VULKAN:      mp_renderer = new CVulkanRenderer();     break;
        case RENDERING_API_OPENGL_3:    mp_renderer = new COpenGL3Renderer();    break;
        case RENDERING_API_OPENGL_4:    mp_renderer = new COpenGL4Renderer();    break;
        case RENDERING_API_DIRECT3D_12: mp_renderer = new CDirect3D12Renderer(); break;
    }

    if(!mp_renderer)
        throw std::bad_alloc();

    // Initializing the renderer
    mp_renderer->Initialize(*rendering_engine_create_info.p_renderer_create_info);

    SLogger::LogInfo("  Renderer initialized.");
}

} // ! namespace

} // ! namespace