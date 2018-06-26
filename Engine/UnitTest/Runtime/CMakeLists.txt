# Copyright (C) 2018-2019 Ordinal Engine
# Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
# See https://vincentcalisto.com/ordinal-engine/

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

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

INCLUDE_DIRECTORIES(
        ${ORDINAL_VK_HEADER_DIR}
        ${ORDINAL_ENGINE_HEADER_DIR}
        ${ORDINAL_THIRD_PARTY_DIR}/GoogleTest/include)

# Gets engine runtime sources
FILE(GLOB_RECURSE ENGINE_RUNTIME_SOURCES
        ${ORDINAL_ENGINE_SOURCE_DIR}/Runtime/Core/*.cpp
        ${ORDINAL_ENGINE_SOURCE_DIR}/Runtime/Network/*.cpp
        ${ORDINAL_ENGINE_SOURCE_DIR}/Runtime/Rendering/*.cpp)

# Get engine runtime headers
FILE(GLOB_RECURSE ENGINE_RUNTIME_HEADERS
        ${ORDINAL_ENGINE_HEADER_DIR}/Runtime/*.hpp
        ${ORDINAL_ENGINE_HEADER_DIR}/Runtime/*.inl
        ${ORDINAL_ENGINE_HEADER_DIR}/Runtime/*.hh)

# Getting sources
SET(TEST_FILES
        # Core/Memory
        Core/Memory/UnitTest_CStackAllocator.cpp)

# Linking
ADD_EXECUTABLE       (${ORDINAL_RUNTIME_UNIT_TEST} ${ENGINE_RUNTIME_SOURCES} ${ENGINE_RUNTIME_HEADERS} ${TEST_FILES})
TARGET_LINK_LIBRARIES(${ORDINAL_RUNTIME_UNIT_TEST} ${COMPILER_DEPENDENCIES} ${PLATFORM_DEPENDENCIES} gtest gtest_main ${ORDINAL_VK_LIB_DIR}/vulkan-1.lib)