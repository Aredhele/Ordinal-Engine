/// Copyright (C) 2018-2019, Ordinal Engine
/// Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
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

/// \file       SocketHandle.hh
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Network/Socket
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_SOCKET_HANDLE_HH_
#define ORDINAL_ENGINE_C_SOCKET_HANDLE_HH_

#include "Runtime/Platform/Configuration/Configuration.hpp"

/// \namespace ord
namespace ord { namespace network {

#if defined(ORDINAL_WINDOWS)
    typedef UINT_PTR SocketHandle;

#else
    typedef int SocketHandle;

#endif

} } // !namespace

#endif // !ORDINAL_ENGINE_C_SOCKET_HANDLE_HH__