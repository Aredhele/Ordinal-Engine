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

/// \file       TVec4.hpp
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Maths/Vector
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_T_VEC_4_HPP__
#define ORDINAL_ENGINE_T_VEC_4_HPP__

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  4D vector partial specialization
/// \class  TVec
/// \tparam N The number of component 4
/// \tparam Tp The type of the components
template<typename Tp>
class TVec<4, Tp>
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
        struct { value_type x; value_type y; value_type z; value_type w; }; ///< The x, y, z, w components
        struct { value_type r; value_type g; value_type b; value_type a; }; ///< The r, g, b, a components

        value_type v[4];     ///< The vector as an array
    };
};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_T_VEC_4_HPP__