# Copyright (C) 2018-2019 Ordinal Engine
# Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# he Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# CMake project settings
PROJECT(OrdinalEngine)
CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

# Checking project structure
INCLUDE(CMake/CMakeConfigDirectory.cmake)

# Defines the game engine version and name
SET(CMAKE_ENGINE_VERSION_MAJOR 0)
SET(CMAKE_ENGINE_VERSION_MINOR 1)
SET(CMAKE_ENGINE_VERSION_PATCH 0)

# Empty for now
SET(GNU_DEPENDENCIES   "")
SET(MSVC_DEPENDENCIES  "")

SET(WIN32_DEPENDENCIES "")
SET(APPLE_DEPENDENCIES "")
SET(UNIX_DEPENDENCIES  "")

SET(ORDINAL_BIN_OUTPUT "")
SET(ORDINAL_LIB_OUTPUT "")

# Displays engine version
MESSAGE(STATUS "Engine : ${ENGINE_NAME} "
         "${CMAKE_ENGINE_VERSION_MAJOR}."
         "${CMAKE_ENGINE_VERSION_MINOR}."
         "${CMAKE_ENGINE_VERSION_PATCH} ")

# Compiler settings
# Using GNU GCC
IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

    SET(ORDINAL_USE_GCC 1)
    SET(COMPILER_DEPENDENCIES ${GNU_DEPENDENCIES})

    ADD_DEFINITIONS(-D ORDINAL_USE_GCC)
    MESSAGE(STATUS "Detected Compiler : ${CMAKE_CXX_COMPILER_ID}")

    # For GCC, setting flags
    SET(CXX_RELEASE_FLAGS   "-Wall -Wextra -O3")
    SET(CXX_DEBUG_FLAGS     "-Wall -Wextra -g -Wdouble-promotion")

# Using Visual Studio C++
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

    SET(ORDINAL_USE_MSVC 1)
    SET(COMPILER_DEPENDENCIES ${WINDOWS_MVSC_DEPENDENCIES})

    ADD_DEFINITIONS(-D ORDINAL_USE_MSVC)
    MESSAGE(STATUS "Detected Compiler : ${CMAKE_CXX_COMPILER_ID}")

    # No flags yet for MVSC
    # For GCC, setting flags
    # SET(CXX_RELEASE_FLAGS "")
    # SET(CXX_DEBUG_FLAGS   "")

ELSE()

    # Unsuported compiler
    SET(COMPILER_DEPENDENCIES "")
    MESSAGE(FATAL_ERROR "Detected Compiler : Unknown, please use GCC or MSVC.")

ENDIF()

SET    (CMAKE_CXX_STANDARD 14)
MESSAGE(STATUS "Compilation CXX standard  : " ${CMAKE_CXX_STANDARD})
MESSAGE(STATUS "Compilation debug   flags : " ${CXX_DEBUG_FLAGS})
MESSAGE(STATUS "Compilation release flags : " ${CXX_RELEASE_FLAGS})

# Platform detection and settings
IF(WIN32)

    # Windows operating system
    SET(ORDINAL_WINDOWS 1)
    SET(PLATFORM_DEPENDENCIES ${WIN32_DEPENDENCIES})
    ADD_DEFINITIONS(-D ORDINAL_WINDOWS)
    MESSAGE(STATUS "Detected platform : Windows")

ELSEIF(UNIX)

    # Unix operating system
    SET(ORDINAL_UNIX 1)
    SET(PLATFORM_DEPENDENCIES ${UNIX_DEPENDENCIES})
    ADD_DEFINITIONS(-D ORDINAL_UNIX)
    MESSAGE(STATUS "Detected platform : Unix")

ELSEIF(APPLE)

    # Mac os operating system
    SET(ORDINAL_APPLE 1)
    SET(PLATFORM_DEPENDENCIES ${APPLE_DEPENDENCIES})
    ADD_DEFINITIONS(-D ORDINAL_APPLE)
    MESSAGE(STATUS "Detected platform : Apple")

ELSE()

    # Not supported
    SET(PLATFORM_NOT_SUPORTED 0)
    SET(PLATFORM_DEPENDENCIES)
    ADD_DEFINITIONS(-D PLATFORM_NOT_SUPORTED)
    MESSAGE(FATAL_ERROR "This plateform is currently not supported")

ENDIF()

SET(ARCHITECTURE "")
CHECK_ARCHITECTURE(ARCHITECTURE)

# Checking architecture
IF(${ARCHITECTURE} MATCHES 32)
    MESSAGE(STATUS "Architecture : 32 bits")
ELSE()
    MESSAGE(STATUS "Architecture : 64 bits")
ENDIF()

# Compilation mode
IF(${CMAKE_BUILD_TYPE} MATCHES Debug)

    # Debug mode
    ADD_DEFINITIONS(-D ORDINAL_DEBUG)

    IF(${ARCHITECTURE} MATCHES 32)
        SET(ORDINAL_BIN_OUTPUT ${ORDINAL_BIN_DIR_DBG_32})
        SET(ORDINAL_LIB_OUTPUT ${ORDINAL_LIB_DIR_DBG_32})
        SET(ORDINAL_RUNTIME    ${ORDINAL_RUNTIME_DBG_32})
    ELSE()
        SET(ORDINAL_BIN_OUTPUT ${ORDINAL_BIN_DIR_DBG_64})
        SET(ORDINAL_LIB_OUTPUT ${ORDINAL_LIB_DIR_DBG_64})
        SET(ORDINAL_RUNTIME    ${ORDINAL_RUNTIME_DBG_64})
    ENDIF()

    MESSAGE(STATUS "Compilation mode  : Debug x" ${ARCHITECTURE})
    MESSAGE(STATUS "Project binary  output : ${ORDINAL_BIN_OUTPUT}")
    MESSAGE(STATUS "Project library output : ${ORDINAL_LIB_OUTPUT}")

    # Setting flags
    IF(COMPILER_GCC)
        # Only for GCC
        set(CMAKE_CXX_FLAGS_DEBUG ${CXX_DEBUG_FLAGS} CACHE STRING "DBG" FORCE)
    ENDIF()

ELSEIF(${CMAKE_BUILD_TYPE} MATCHES Release)

    # Release mode
    ADD_DEFINITIONS(-D ORDINAL_RELEASE)
    IF(${ARCHITECTURE} MATCHES 32)
        SET(ORDINAL_BIN_OUTPUT ${ORDINAL_BIN_DIR_REL_32})
        SET(ORDINAL_LIB_OUTPUT ${ORDINAL_LIB_DIR_REL_32})
        SET(ORDINAL_RUNTIME    ${ORDINAL_RUNTIME_REL_32})
    ELSE()
        SET(ORDINAL_BIN_OUTPUT ${ORDINAL_BIN_DIR_REL_64})
        SET(ORDINAL_LIB_OUTPUT ${ORDINAL_LIB_DIR_REL_64})
        SET(ORDINAL_RUNTIME    ${ORDINAL_RUNTIME_REL_64})
    ENDIF()

    MESSAGE(STATUS "Compilation mode  : Release x" ${ARCHITECTURE})
    MESSAGE(STATUS "Project binary  output : ${ORDINAL_BIN_OUTPUT}")
    MESSAGE(STATUS "Project library output : ${ORDINAL_LIB_OUTPUT}")

    # Setting flags
    IF(COMPILER_GCC)
        # Only for GCC
        set(CMAKE_CXX_FLAGS_DEBUG ${CXX_RELEASE_FLAGS} CACHE STRING "REL" FORCE)
    ENDIF()

ELSE()

    # No mode
    MESSAGE(FATAL_ERROR "No build type, please configure it")

ENDIF()

# Avoiding the Release/Debug subdirectories
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY         ${ORDINAL_BIN_OUTPUT})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${ORDINAL_BIN_OUTPUT})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ORDINAL_BIN_OUTPUT})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${ORDINAL_LIB_OUTPUT})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${ORDINAL_LIB_OUTPUT})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${ORDINAL_LIB_OUTPUT})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${ORDINAL_LIB_OUTPUT})

# Obsolete, configured in CMakeSettings.json
# SET(gtest_force_shared_crt ON CACHE BOOL FORCE "Always use msvcrt.dll" )

# Vulkan
FILE(TO_CMAKE_PATH $ENV{VK_SDK_PATH} ORDINAL_SDK_VK_PATH)

IF(${ARCHITECTURE} MATCHES 32)
    SET(ORDINAL_VK_HEADER_DIR ${ORDINAL_SDK_VK_PATH}/Include/)
    SET(ORDINAL_VK_LIB_DIR    ${ORDINAL_SDK_VK_PATH}/Lib32/)
ELSE()
    SET(ORDINAL_VK_HEADER_DIR ${ORDINAL_SDK_VK_PATH}/Include/)
    SET(ORDINAL_VK_LIB_DIR    ${ORDINAL_SDK_VK_PATH}/Lib/)
ENDIF()

ADD_SUBDIRECTORY(Engine)