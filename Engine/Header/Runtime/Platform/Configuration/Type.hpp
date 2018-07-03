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

/// \file       Type.hpp
/// \date       03/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Platform/Configuration
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_TYPE_HPP__
#define ORDINAL_ENGINE_TYPE_HPP__

#include <cstdint>

static_assert(sizeof(int8_t )  == 1, "sizeof(int8_t )  should be 1.");
static_assert(sizeof(int16_t)  == 2, "sizeof(int16_t)  should be 2.");
static_assert(sizeof(int32_t)  == 4, "sizeof(int32_t)  should be 4.");
static_assert(sizeof(int64_t)  == 8, "sizeof(int64_t)  should be 8.");
static_assert(sizeof(uint8_t ) == 1, "sizeof(uint8_t ) should be 1.");
static_assert(sizeof(uint16_t) == 2, "sizeof(uint16_t) should be 2.");
static_assert(sizeof(uint32_t) == 4, "sizeof(uint32_t) should be 4.");
static_assert(sizeof(uint64_t) == 8, "sizeof(uint64_t) should be 8.");

/// \namespace Ord
namespace Ord
{

using Int8    = int8_t;    ///< A signed  8 bits long type
using Int16   = int16_t;   ///< A signed 16 bits long type
using Int32   = int32_t;   ///< A signed 32 bits long type
using Int64   = int64_t;   ///< A signed 64 bits long type
using IntPtr  = intptr_t;  ///< A signed pointer type
using UInt8   = uint8_t;   ///< An unsigned  8 bits long type
using UInt16  = uint16_t;  ///< An unsigned 16 bits long type
using UInt32  = uint32_t;  ///< An unsigned 32 bits long type
using UInt64  = uint64_t;  ///< An unsigned 64 bits long type
using UIntPtr = uintptr_t; ///< An unsigned pointer type

} // !namespace

#endif // !ORDINAL_ENGINE_TYPE_HPP__