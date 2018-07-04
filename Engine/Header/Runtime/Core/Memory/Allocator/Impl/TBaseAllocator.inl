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

/// \file       TBaseAllocator.inl
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory/Allocator/Impl
/// \author     Vincent STEHLY--CALISTO

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  Returns a pointer on the given variable
/// \param  x A reference on a variable
/// \return A pointer on the given variable
template<typename Tp>
/* inline */ Tp* TBaseAllocator<Tp>::Address(reference x) const ORDINAL_NOEXCEPT
{
    return std::addressof(x);
}

/// \brief  Returns a const pointer on the given variable
/// \param  x A const reference on a variable
/// \return A const pointer on the given variable
template<typename Tp>
/* inline */ const Tp* TBaseAllocator<Tp>::Address(const_reference x) const ORDINAL_NOEXCEPT
{
    return std::addressof(x);
}

} // !namespace

} // !namespace