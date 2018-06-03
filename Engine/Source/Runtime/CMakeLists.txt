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

# Adds all runtime header
INCLUDE_DIRECTORIES(
        ${ORDINAL_ENGINE_HEADER_DIR}
        ${ORDINAL_VK_HEADER_DIR})

# Gets all source files
FILE(GLOB_RECURSE ENGINE_SOURCES *.cpp)
FILE(GLOB_RECURSE ENGINE_HEADERS
        ${ORDINAL_ENGINE_HEADER_DIR}/*.hpp
        ${ORDINAL_ENGINE_HEADER_DIR}/*.inl
        ${ORDINAL_ENGINE_HEADER_DIR}/*.hh)

ADD_EXECUTABLE(${ORDINAL_RUNTIME}
        ${ENGINE_SOURCES}
        ${ENGINE_HEADERS} ../../Header/Runtime/Rendering/Helper/VulkanHelper.hh)

ADD_CUSTOM_TARGET(ResourcesCopy)
ADD_DEPENDENCIES (${ORDINAL_RUNTIME} ResourcesCopy)

# Linking ...
TARGET_LINK_LIBRARIES(${ORDINAL_RUNTIME}
        ${COMPILER_DEPENDENCIES}
        ${PLATFORM_DEPENDENCIES}
        ${ORDINAL_VK_LIB_DIR}/vulkan-1.lib)

# Copy all resources on engine build
ADD_CUSTOM_COMMAND(TARGET ResourcesCopy PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${ORDINAL_ENGINE_RESOURCE_DIR} ${ORDINAL_BIN_OUTPUT}/Resources
        COMMENT "[INFO] Copying shared files ...")