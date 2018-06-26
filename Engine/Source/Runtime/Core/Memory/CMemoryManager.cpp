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

/// \file       CMemoryManager.cpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#include <cstring>
#include <stdexcept>

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Core/Memory/CMemoryManager.hpp"
#include "Runtime/Core/Memory/CMemoryTracker.hpp"

/// \namespace ord
namespace ord
{

/// \namespace core
namespace core
{

/* static */ bool    CMemoryManager::s_initialized                   = false;
/* static */ bool    CMemoryManager::s_memory_logging_enabled        = false;
/* static */ bool    CMemoryManager::s_memory_initialization_enabled = false;
/* static */ uint8_t CMemoryManager::s_memory_initialization_byte    = 0xFF;

/// \brief Private destructor
CMemoryManager::~CMemoryManager()
{
    Release();
}

/// \brief  Allocates the given amount of bytes and returns a pointer on the allocated memory
/// \param  size The amount of bytes to allocate
/// \param  array_allocation Is this an array allocation ?
/// \param  p_function_name The caller function name
/// \param  line The called line
/// \return A pointer on the allocated memory
/* static */ void* CMemoryManager::Allocate(std::size_t size, bool array_allocation, const char* p_function_name, unsigned int line)
{
    if(!s_initialized)
    {
        SLogger::LogError("Did you forget to initialize the memory manager ?");
        SLogger::LogError("Memory will not be allocated, aborting call.");
        throw std::runtime_error("Memory manager not initialized");
    }

    std::size_t extra_size = 0;
    uint8_t*    pointer    = nullptr;

#ifdef ORDINAL_DEBUG
    extra_size = sizeof(CMemoryTracker::SBlock);
    pointer    = static_cast<uint8_t *>(std::malloc(size + extra_size));
#else
    pointer = static_cast<uint8_t *>(std::malloc(size));
#endif

    if(!pointer)
    {
        SLogger::LogError("Failed to allocate %llu bytes. Malloc returned nullptr");
        throw std::bad_alloc();
    }

    if(s_memory_initialization_enabled)
    {
        std::memset(pointer, s_memory_initialization_byte, size + extra_size);
    }

#ifdef ORDINAL_DEBUG
    CMemoryTracker::RecordAllocation(pointer, size, array_allocation, p_function_name, line);
#endif

    if(s_memory_logging_enabled)
    {
        // TODO
    }

    return pointer + extra_size;
}

/// \brief  Deallocates the memory at the given address
/// \param  array_allocation Was the allocation an array allocation ?
/// \param  p_function_name The caller function name
/// \param  line The called line
/* static */ void CMemoryManager::Deallocate(void *pointer, bool array_allocation, const char* p_function_name, unsigned int line)
{
    if(!s_initialized)
    {
        SLogger::LogError("Did you forget to initialize the memory manager ?");
        SLogger::LogError("Memory will not be freed, aborting call.");
        throw std::runtime_error("Memory manager already initialized");
    }

    if(!pointer)
    {
        SLogger::LogWaring("Tried to free a null pointer.");
        return;
    }

#ifdef ORDINAL_DEBUG
    // Computing the true address of the block
    auto* p_block = static_cast<uint8_t *>(pointer) - sizeof(CMemoryTracker::SBlock);
    CMemoryTracker::RecordDeallocation(p_block, array_allocation, p_function_name, line);

    // Updating the pointer to free
    pointer = p_block;
#endif

    std::free(pointer);
}

/// \brief  Tells if the memory logging is enabled
/// \return True or false
/* static */ bool CMemoryManager::IsMemoryLoggingEnabled()
{
    return s_memory_logging_enabled;
}

/// \brief  Tells if the memory initialization is enabled
/// \return True or false
/* static */ bool CMemoryManager::IsMemoryInitializationEnabled()
{
    return s_memory_initialization_enabled;
}

/// \brief Initializes the memory manager
/// \param manager_create_info
/* static */ void CMemoryManager::Initialize(const SMemoryManagerCreateInfo& manager_create_info)
{
    SLogger::LogInfo("Memory manager initialization ...");

    if(s_initialized)
    {
        Release();
    }

    s_memory_logging_enabled        = manager_create_info.memory_logging_enabled;
    s_memory_initialization_enabled = manager_create_info.memory_initialization_enabled;
    s_memory_initialization_byte    = manager_create_info.memory_initialization_byte;

    s_initialized = true;

#ifdef ORDINAL_DEBUG
    CMemoryTracker::Initialize();
#endif

    SLogger::LogInfo("Memory manager fully initialized.");
}

/// \brief Releases the memory manager
/* static */ void CMemoryManager::Release()
{
    if(!s_initialized)
    {
        s_initialized = false;
    }

#ifdef ORDINAL_DEBUG
    CMemoryTracker::Release();
#endif

}

} // !namespace

} // !namespace