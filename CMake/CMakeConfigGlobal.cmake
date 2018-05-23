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

# Path
SET(ORDINAL_ROOT_DIR        ${CMAKE_SOURCE_DIR})
SET(ORDINAL_BIN_DIR         ${ORDINAL_ROOT_DIR}/Bin)
SET(ORDINAL_BIN_DIR_DBG     ${ORDINAL_BIN_DIR}/Debug)
SET(ORDINAL_BIN_DIR_REL     ${ORDINAL_BIN_DIR}/Release)
SET(ORDINAL_LIB_DIR         ${ORDINAL_ROOT_DIR}/Lib)
SET(ORDINAL_LIB_DIR_DBG     ${ORDINAL_LIB_DIR}/Debug)
SET(ORDINAL_LIB_DIR_REL     ${ORDINAL_LIB_DIR}/Release)
SET(ORDINAL_ENGINE_DIR      ${ORDINAL_ROOT_DIR}/Engine)
SET(ORDINAL_GAME_DIR        ${ORDINAL_ROOT_DIR}/Game)
SET(ORDINAL_THIRD_PARTY_DIR ${ORDINAL_ENGINE_DIR}/ThirdParty)
SET(ORDINAL_UNIT_TEST_DIR   ${ORDINAL_THIRD_PARTY_DIR}/UnitTest)
SET(ORDINAL_GLFW_DIR        ${ORDINAL_THIRD_PARTY_DIR}/Glfw)

# Include
SET(ORDINAL_GTEST_INC_DIR   ${ORDINAL_UNIT_TEST_DIR}/GoogleTest/include)
SET(ORDINAL_GMOCK_INC_DIR   ${ORDINAL_UNIT_TEST_DIR}/GoogleMock/include)

# Name
SET(ORDINAL_RUNTIME OrdinalRuntime)
SET(ORDINAL_EDITOR  OrdinalEditor)