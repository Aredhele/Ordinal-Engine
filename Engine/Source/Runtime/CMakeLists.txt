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
        ${ORDINAL_ENGINE_DIR}/Header/
        ${ORDINAL_SDK_VK}/Include/
        ${ORDINAL_THIRD_PARTY_DIR}/Glm/
        ${ORDINAL_THIRD_PARTY_DIR}/ImGUI/Header/)

ADD_EXECUTABLE(${ORDINAL_RUNTIME}
        Main.cpp
        Core/Debug/SLogger.cpp
        Rendering/Window/CWindow.cpp)

# But tests depends on GTEST and GMOCK
ADD_DEPENDENCIES(${ORDINAL_RUNTIME} glfw ResourcesCopy ImGUI)

# Linking ...
TARGET_LINK_LIBRARIES(${ORDINAL_RUNTIME} ${COMPILER_DEPENDENCIES} ${ORDINAL_SDK_VK}/Lib/vulkan-1.lib glfw ImGUI ${PLATFORM_DEPENDENCIES})

ADD_CUSTOM_TARGET(ResourcesCopy)

# Copy all resources on engine build
ADD_CUSTOM_COMMAND(TARGET ResourcesCopy PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${ORDINAL_ENGINE_DIR}/Resources ${ORDINAL_BIN_OUTPUT}/Resources
        COMMENT "[INFO] Copying shared files ...")
