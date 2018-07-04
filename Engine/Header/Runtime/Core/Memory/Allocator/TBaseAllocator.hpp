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

/// \file       TBaseAllocator.hpp
/// \date       04/07/2018 
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory/Allocator
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_T_BASE_ALLOCATOR_HPP__
#define ORDINAL_ENGINE_T_BASE_ALLOCATOR_HPP__

#include <memory>
#include "Runtime/Platform/Configuration/Configuration.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  Base class for allocators
/// \tparam The type of objects to allocate
/// \class  TBaseAllocator
template<typename Tp>
class TBaseAllocator
{
public:

    using size_type       = size_t;
    using value_type      = Tp;
    using difference_type = ptrdiff_t;
    using pointer         = Tp*;
    using reference       = Tp &;
    using const_pointer   = const Tp*;
    using const_reference = const Tp &;

public:

    /// \brief  Returns a pointer on the given variable
    /// \param  x A reference on a variable
    /// \return A pointer on the given variable
    inline ORDINAL_CXX17_CONSTEXPR pointer Address(reference x) const ORDINAL_NOEXCEPT;

    /// \brief  Returns a const pointer on the given variable
    /// \param  x A const reference on a variable
    /// \return A const pointer on the given variable
    inline ORDINAL_CXX17_CONSTEXPR const_pointer Address(const_reference x) const ORDINAL_NOEXCEPT;
};

} // !namespace

} // !namespace

#include "Runtime/Core/Memory/Allocator/Impl/TBaseAllocator.inl"

#endif // !ORDINAL_ENGINE_T_BASE_ALLOCATOR_HPP__