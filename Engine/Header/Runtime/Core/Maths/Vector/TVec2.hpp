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

/// \file       TVec2.hpp
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Maths/Vector
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_T_VEC_2_HPP__
#define ORDINAL_ENGINE_T_VEC_2_HPP__

#include "Runtime/Core/Maths/Vector/TVec.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  2D vector partial specialization
/// \class  TVec
/// \tparam N The number of component 2
/// \tparam Tp The type of the components
template<typename Tp>
class TVec<2, Tp>
{
public:

    using value_type      = Tp;
    using pointer         = Tp*;
    using reference       = Tp&;
    using const_pointer   = const Tp*;
    using const_reference = const Tp&;

public:

    union
    {
        struct { value_type x; value_type y; }; ///< The x, y components
        struct { value_type r; value_type g; }; ///< The r, g components

        value_type v[2];     ///< The vector as an array
    };
};

} // !namespace

} // !namespace

#include "Runtime/Core/Maths/Vector/Impl/TVec2_FPU.inl"

#endif // !ORDINAL_ENGINE_T_VEC_2_HPP__