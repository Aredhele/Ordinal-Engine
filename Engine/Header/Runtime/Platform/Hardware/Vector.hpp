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

/// \file       Vector.hpp
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Platform/Hardware
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_VECTOR_HPP__
#define ORDINAL_ENGINE_VECTOR_HPP__

#include "Runtime/Core/Assertion/Assert.hpp"
#include "Runtime/Platform/Hardware/Configuration.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Platform
namespace Platform
{

/// \brief  Shuffles vector index
/// \param  A0 Selects the A0 element into the first vector
/// \param  A1 Selects the A1 element into the first vector
/// \param  B2 Selects the B2 element into the second vector
/// \param  B3 Selects the B3 element into the second vector
/// \return The mask to shuffle the vector
ORDINAL_CONSTEXPR
inline UInt32 MakeShuffleMask(
    const UInt8 A0, const UInt8 A1,
    const UInt8 B2, const UInt8 B3) ORDINAL_NOEXCEPT
{
    return ((A0) | ((A1) << 2) | ((B2) << 4) | ((B3) << 6));
}

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_VECTOR_HPP__