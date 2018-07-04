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
/// \package    Runtime/Core/Maths/Vector
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_MATHS_VECTOR_HPP__
#define ORDINAL_ENGINE_MATHS_VECTOR_HPP__

#include "Runtime/Core/Maths/Vector/TVec1.hpp"
#include "Runtime/Core/Maths/Vector/TVec2.hpp"
#include "Runtime/Core/Maths/Vector/TVec3.hpp"
#include "Runtime/Core/Maths/Vector/TVec4.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

using Vec1 = TVec<1, float>;
using Vec2 = TVec<2, float>;

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_MATHS_VECTOR_HPP__