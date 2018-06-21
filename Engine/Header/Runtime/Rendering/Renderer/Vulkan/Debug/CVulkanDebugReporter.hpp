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

/// \file       CVulkanDebugReporter.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan/Debug
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_VULKAN_DEBUG_REPORTER_HPP__
#define ORDINAL_ENGINE_C_VULKAN_DEBUG_REPORTER_HPP__

#include "Runtime/Platform/Configuration/Configuration.hh"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief  Stores report info
/// \struct SDebugCallbackReportInfo
struct SDebugCallbackReportInfo
{
    VkDebugReportFlagsEXT      flags;           ///< Indicates the VkDebugReportFlagBitsEXT that triggered this callback
    VkDebugReportObjectTypeEXT object_type;     ///< Specifies the type of object being used or created when event was triggered
    uint64_t                   source_object;   ///< Gives the object where the issue was detected
    size_t                     location;        ///< Indicates the location of the trigger
    int32_t                    message_code;    ///< This is a layer-defined value indicating what test triggered this callback
    const char*                p_layer_prefix;  ///< This is the abbreviation of the component making the callback
    const char*                p_message;       ///< This a null-terminated string detailing the trigger conditions
    void*                      p_user_data;     ///< This the user data given when the DebugReportCallback was created
};

/// \brief Manages and displays debug reports
/// \class CVulkanDebugReporter
class CVulkanDebugReporter
{
public:

    /// \brief Manages and displays the report info
    /// \param callback_report_info The report info
    /// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
    VkBool32 Report(const SDebugCallbackReportInfo& callback_report_info);

private:

    /// \brief Displays the information report info
    /// \param callback_report_info The report info
    /// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
    VkBool32 ReportInformation(const SDebugCallbackReportInfo& callback_report_info);

    /// \brief Displays the debug report info
    /// \param callback_report_info The report info
    /// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
    VkBool32 ReportDebug(const SDebugCallbackReportInfo& callback_report_info);

    /// \brief Displays the warning report info
    /// \param callback_report_info The report info
    /// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
    VkBool32 ReportWarning(const SDebugCallbackReportInfo& callback_report_info);

    /// \brief Displays the performance warning report info
    /// \param callback_report_info The report info
    /// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
    VkBool32 ReportPerformanceWarning(const SDebugCallbackReportInfo& callback_report_info);

    /// \brief Displays the error report info
    /// \param callback_report_info The report info
    /// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
    VkBool32 ReportError(const SDebugCallbackReportInfo& callback_report_info);

};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_C_VULKAN_DEBUG_REPORTER_HPP__