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

/// \file       SLogger.cpp
/// \date       09/02/2018
/// \project    Ordinal Engine
/// \package    Core/Debug
/// \author     Vincent STEHLY--CALISTO

#include <cstdio>
#include <cstdarg>
#include "Runtime/Core/Debug/SLogger.hpp"

/// \brief  Helper macro to print variadic
///         parameters in the given file
#define __VA_LOG(FILE, LEVEL, FORMAT)     \
    va_list  argList;                     \
    va_start(argList, FORMAT);            \
        fprintf (FILE, LEVEL);            \
        vfprintf(FILE, FORMAT, argList);  \
        fprintf (FILE, "\n");             \
    va_end  (argList);                    \

/// \namespace ord
namespace Ord
{

/// \brief Logs a user message on stdout
/// \param sz_format The format of the message
/// \param ... Variadic c-style arguments
/* static */ void SLogger::LogUser(const char * sz_format, ...)
{
    __VA_LOG(stdout, "[ORDINAL][USER] : ", sz_format);
}

/// \brief Logs an information message on stdout
/// \param sz_format The format of the message
/// \param ... Variadic c-style arguments
/* static */ void SLogger::LogInfo(const char * sz_format, ...)
{
    __VA_LOG(stdout, "[ORDINAL][INFO] : ", sz_format);
}

/// \brief Logs a warning message on stdout
/// \param sz_format The format of the message
/// \param ... Variadic c-style arguments
/* static */ void SLogger::LogWaring(const char * sz_format, ...)
{
    __VA_LOG(stdout, "[ORDINAL][WARN] : ", sz_format);
}

/// \brief Logs an error message on stderr
/// \param sz_format The format of the message
/// \param ... Variadic c-style arguments
/* static */ void SLogger::LogError(const char * sz_format, ...)
{
    __VA_LOG(stderr, "[ORDINAL][ERRO] : ", sz_format);
}

} // !namespace