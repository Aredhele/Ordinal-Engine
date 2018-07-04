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

/// \file       TMallocAllocator.hpp
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_T_MALLOC_ALLOCATOR_HPP__
#define ORDINAL_ENGINE_T_MALLOC_ALLOCATOR_HPP__

#include "Runtime/Core/Memory/Allocator/TBaseAllocator.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  Default allocator using malloc
/// \tparam Tp The type of objects to allocate
/// \class  TMallocAllocator
template<typename Tp>
class TMallocAllocator : public TBaseAllocator<Tp>
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

    /// \brief Default constructor
    TMallocAllocator() ORDINAL_NOEXCEPT ORDINAL_DEFAULT;

    /// \brief Default copy constructor
    /// \param other The other allocator
    TMallocAllocator(const TMallocAllocator& other) ORDINAL_NOEXCEPT ORDINAL_DEFAULT;

    /// \brief Default destructor
    ~TMallocAllocator() ORDINAL_NOEXCEPT ORDINAL_DEFAULT;

    /// \brief  Allocates n * sizeof(Tp) bytes
    /// \param  n The number of elements to allocate
    /// \return A pointer on the allocated memory
    inline pointer Allocate(size_type n);

    /// \brief  Allocates n * sizeof(Tp) bytes
    /// \param  n The number of elements to allocate
    /// \return A pointer on the allocated memory
    inline void Deallocate(pointer p);

    /// \brief  Constructs an object at given memory location
    /// \tparam Up The pointer type
    /// \tparam Args The arguments to construct the object
    /// \param  p The pointer to the memory
    /// \param  args The arguments to construct the object
    template<typename Up, typename... Args>
    inline void Construct(Up* p, Args&&... args);

    /// \brief  Destroys an object at the given memory location
    /// \tparam Up The pointer type
    /// \param  p The pointer on the object
    template<typename Up>
    inline void Destroy(Up* p);
};

} // !namespace

} // !namespace

#include "Runtime/Core/Memory/Allocator/Impl/TMallocAllocator.inl"

#endif // !ORDINAL_ENGINE_T_MALLOC_ALLOCATOR_HPP__