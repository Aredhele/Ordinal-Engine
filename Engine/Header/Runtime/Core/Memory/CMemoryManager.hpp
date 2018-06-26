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

/// \file       CMemoryManager.hpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_MEMORY_MANAGER_HPP__
#define ORDINAL_ENGINE_C_MEMORY_MANAGER_HPP__

#include <cstddef> ///< std::size_t
#include <cstdlib> ///< std::malloc, std::free
#include <cstdint> ///< uint8_t

/// \namespace ord
namespace ord
{

/// \namespace core
namespace core
{

/// \brief  Contains all needed information to initialize the memory manager
/// \struct SMemoryManagerCreateInfo
struct SMemoryManagerCreateInfo
{
    bool    memory_logging_enabled;
    bool    memory_initialization_enabled;
    uint8_t memory_initialization_byte;
};

/// \brief Manages memory allocations
/// \class CMemoryManager
class CMemoryManager
{
public:

    /// \brief  Allocates the given amount of bytes and returns a pointer on the allocated memory
    /// \param  size The amount of bytes to allocate
    /// \param  array_allocation Is this an array allocation ?
    /// \param  sz_function_name The caller function name
    /// \param  line The called line
    /// \return A pointer on the allocated memory
    static void* Allocate(std::size_t size, bool array_allocation = false, const char* sz_function_name = nullptr, unsigned int line = 0);

    /// \brief  Deallocates the memory at the given address
    /// \param  array_allocation Was the allocation an array allocation ?
    /// \param  sz_function_name The caller function name
    /// \param  line The called line
    static void Deallocate(void *pointer, bool array_allocation = false, const char* sz_function_name = nullptr, unsigned int line = 0);

    /// \brief  Tells if the memory logging is enabled
    /// \return True or false
    static bool IsMemoryLoggingEnabled();

    /// \brief  Tells if the memory initialization is enabled
    /// \return True or false
    static bool IsMemoryInitializationEnabled();

private:

    /// \brief Private default constructor
    CMemoryManager() = default;

    /// \brief Private destructor
    ~CMemoryManager();

    /// \brief Initializes the memory manager
    /// \param manager_create_info
    static void Initialize(const SMemoryManagerCreateInfo& manager_create_info);

    /// \brief Releases the memory manager
    static void Release();

private:

    static bool    s_initialized;                     ///< Is the manager initialized ?
    static bool    s_memory_logging_enabled;          ///< Should the memory be logged ?
    static bool    s_memory_initialization_enabled;   ///< Should the memory be initialized ?
    static uint8_t s_memory_initialization_byte;      ///< The byte to initialize the memory with
};

} // !namespace

} // !namespace

#define ORDINAL_ALLOCATE  (SIZE,    IS_ARRAY) CMemoryManager::Allocate  (SIZE,    IS_ARRAY, __func__, __LINE__)
#define ORDINAL_DEALLOCATE(POINTER, IS_ARRAY) CMemoryManager::Deallocate(POINTER, IS_ARRAY, __func__, __LINE__)

#endif // !ORDINAL_ENGINE_C_MEMORY_MANAGER_HPP__