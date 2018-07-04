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
using Vec3 = TVec<3, float>;
using Vec4 = TVec<4, float>;

using Vec1d = TVec<1, double>;
using Vec2d = TVec<2, double>;
using Vec3d = TVec<3, double>;
using Vec4d = TVec<4, double>;

using Vec1i = TVec<1, Int32>;
using Vec2i = TVec<2, Int32>;
using Vec3i = TVec<3, Int32>;
using Vec4i = TVec<4, Int32>;

using Vec1u = TVec<1, UInt32>;
using Vec2u = TVec<2, UInt32>;
using Vec3u = TVec<3, UInt32>;
using Vec4u = TVec<4, UInt32>;

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_MATHS_VECTOR_HPP__