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
        ${ORDINAL_ENGINE_HEADER_DIR}/
        ${ORDINAL_THIRD_PARTY_DIR}/GoogleTest/include/)

# Getting sources
SET(SOURCES_FILES
        # Core/Memory
        Core/Memory/UnitTest_CStackAllocator.cpp)

# Linking
ADD_EXECUTABLE       (OrdinalRuntimeUnitTest ${SOURCES_FILES})
TARGET_LINK_LIBRARIES(OrdinalRuntimeUnitTest gtest gtest_main)