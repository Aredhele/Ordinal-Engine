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

/// \file       COrdinalRuntime.hpp
/// \date       29/06/2018 
/// \project    Ordinal Engine
/// \package    Runtime
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_ORDINAL_RUNTIME_HPP__
#define ORDINAL_ENGINE_C_ORDINAL_RUNTIME_HPP__

#include "Runtime/Rendering/CRenderingEngine.hpp"

/// \namespace ord
namespace ord
{

/// \brief Main engine class
/// \class COrdinalRuntime
class COrdinalRuntime
{
public:

    /// \brief Destructor
    ~COrdinalRuntime();

    /// \brief Initializes the engine
    void Initialize();

    /// \brief Starts the engine
    void Run();

    /// \brief Releases the engine
    void Release();

private:

};

} // !namespace 

#endif // !ORDINAL_ENGINE_C_ORDINAL_RUNTIME_HPP__