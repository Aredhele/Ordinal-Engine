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

/// \file       CMemoryTracker.cpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Memory/CMemoryTracker.hpp"

/// \namespace ord
namespace ord
{

/// \namespace core
namespace core
{

/// \brief Destructor
CMemoryTracker::~CMemoryTracker()
{
    Release();
}

/// \brief Records an allocation in the memory tracker
/// \param p_block The allocated block
/// \param size The size of the allocated memory
/// \param is_array Tells if the allocation is an array allocation
/// \param p_caller_file The caller file
/// \param caller_line Thee caller line
/* static */ void core::CMemoryTracker::RecordDeallocation(uint8_t* p_block, bool is_array, const char* p_caller_file, unsigned int caller_line)
{

}

/// \brief Records a deallocation in the memory tracker
/// \param p_block The allocated block
/// \param is_array Tells if the allocation is an array allocation
/// \param p_caller_file The caller file
/// \param caller_line Thee caller line
/* static */ void core::CMemoryTracker::RecordAllocation(uint8_t* p_block, std::size_t size, bool is_array, const char* p_caller_file, unsigned int caller_line)
{

}

/// \brief Initializes the memory tracker
void CMemoryTracker::Initialize()
{

}

/// \brief Releases the memory tracker
void CMemoryTracker::Release()
{

}

} // !namespace

} // !namespace