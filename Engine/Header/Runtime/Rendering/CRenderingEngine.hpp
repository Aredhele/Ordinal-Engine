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

/// \file       CRenderingEngine.hpp
/// \date       29/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_RENDERING_ENGINE_HPP__
#define ORDINAL_ENGINE_C_RENDERING_ENGINE_HPP__

#include "Runtime/Rendering/Renderer/IRenderer.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief  TODO
/// \struct SRenderingEngineCreateInfo
struct SRenderingEngineCreateInfo
{
    ERenderingAPI        e_renderering_api;      ///< TODO
    SRendererCreateInfo* p_renderer_create_info; ///< TODO
};

/// \brief TODO
/// \class CRenderingEngine
class CRenderingEngine
{
public:

    /// \brief  Creates an instance of the Rendering engine
    /// \return The instance of the rendering engine
    static CRenderingEngine* GetInstance();

public:

    /// \brief Deletes the copy constructor
    CRenderingEngine(const CRenderingEngine& other) = delete;

    /// \brief Deletes the assignment operator
    void operator=  (const CRenderingEngine& other) = delete;

    /// \brief Initializes the rendering engine
    /// \param rendering_engine_create_info The info to create the rendering engine
    void Initialize(const SRenderingEngineCreateInfo& rendering_engine_create_info);

    /// \brief Releases the rendering engine
    void Release();

private:

    /// \brief Private constructor
    CRenderingEngine();

    /// \brief Private destructor
    ~CRenderingEngine();

    /// \brief Initializes the renderer
    /// \param rendering_engine_create_info The info to create the rendering engine
    void InitializeRenderer(const SRenderingEngineCreateInfo &rendering_engine_create_info);

private:

    IRenderer* mp_renderer  = nullptr; ///< TODO
};

} // ! namespace

} // ! namespace

#endif // !ORDINAL_ENGINE_C_RENDERING_ENGINE_HPP__