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

/// \file       CVulkanDebugReporter.cpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan/Debug
/// \author     Vincent STEHLY--CALISTO

#include <string>

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/Debug/CVulkanDebugReporter.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief Manages and displays the the report info
/// \param callback_report_info The report info
/// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
VkBool32 CVulkanDebugReporter::Report(const SDebugCallbackReportInfo& callback_report_info)
{
    switch(callback_report_info.flags)
    {
        case VK_DEBUG_REPORT_INFORMATION_BIT_EXT:         return ReportInformation(callback_report_info);
        case VK_DEBUG_REPORT_WARNING_BIT_EXT:             return ReportWarning(callback_report_info);
        case VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT: return ReportPerformanceWarning(callback_report_info);
        case VK_DEBUG_REPORT_ERROR_BIT_EXT:               return ReportError(callback_report_info);
        case VK_DEBUG_REPORT_DEBUG_BIT_EXT:               return ReportDebug(callback_report_info);

        default:
        {
            SLogger::LogInfo("Callback report info flag unknown");
            return VK_FALSE;
        }
    }
}

/// \brief Displays the information report info
/// \param callback_report_info The report info
/// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
VkBool32 CVulkanDebugReporter::ReportInformation(const SDebugCallbackReportInfo& callback_report_info)
{
    return VK_FALSE;
}

/// \brief Displays the debug report info
/// \param callback_report_info The report info
/// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
VkBool32 CVulkanDebugReporter::ReportDebug(const SDebugCallbackReportInfo& callback_report_info)
{
    return VK_FALSE;
}

/// \brief Displays the warning report info
/// \param callback_report_info The report info
/// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
VkBool32 CVulkanDebugReporter::ReportWarning(const SDebugCallbackReportInfo& callback_report_info)
{
    SLogger::LogWaring("Report warning : @[%s] : %s",
                       callback_report_info.p_layer_prefix,
                       callback_report_info.p_message);
    return VK_TRUE;
}

/// \brief Displays the performance warning report info
/// \param callback_report_info The report info
/// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
VkBool32 CVulkanDebugReporter::ReportPerformanceWarning(const SDebugCallbackReportInfo& callback_report_info)
{
    SLogger::LogWaring("Report performance warning : @[%s] : %s",
                       callback_report_info.p_layer_prefix,
                       callback_report_info.p_message);
    return VK_TRUE;
}

/// \brief Displays the error report info
/// \param callback_report_info The report info
/// \return VK_TRUE if the vulkan call should be aborted, else VK_FALSE
VkBool32 CVulkanDebugReporter::ReportError(const SDebugCallbackReportInfo& callback_report_info)
{
    SLogger::LogError("Report error : @[%s] : %s",
                      callback_report_info.p_layer_prefix,
                      callback_report_info.p_message);
    return VK_TRUE;
}

} // !namespace

} // !namespace