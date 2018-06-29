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
#include "Runtime/Platform/Configuration/Configuration.hh"

/// \brief Ordinal engine entry points
int Ordinal_EntryPoint(int argc, char ** argv)
{
    ord::COrdinalRuntime ordinal_runtime;

    try
    {
        ordinal_runtime.Initialize();
        ordinal_runtime.Run();
        ordinal_runtime.Release();
    }
    catch (const std::runtime_error& error)
    {
        // TODO
    }

    // TODO
}