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

/// \file       Window_win32.cpp
/// \date       09/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Window
/// \author     Vincent STEHLY--CALISTO

#include <iostream>
#include <stdexcept>
#include <Runtime/Rendering/Renderer/IWindow.hpp>

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Core/Assertion/Assert.hpp"
#include "Runtime/Rendering/Renderer/IWindow.hpp"

#ifdef ORDINAL_PLATFORM_WINDOWS

LRESULT CALLBACK WindowEventHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    auto p_window = reinterpret_cast<Ord::Rendering::IWindow*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));

    switch(msg)
    {
        case WM_CLOSE:
        {
            if(p_window)
                p_window->Release();

            break;
        }

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }

        case WM_SIZE:
        {
            if(p_window)
                p_window->Resize();

            break;
        }

        default:
        {
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }

    }

    return 0;
}

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/* static */ uint64_t IWindow::m_win32_class_counter = 0;

void IWindow::InitializeOS()
{
    WNDCLASSEX window_class {};
    ORD_ASSERT_GT(m_window_width,  0);
    ORD_ASSERT_GT(m_window_height, 0);

    m_win32_instance   = GetModuleHandle(nullptr);
    m_win32_class_name = std::string(mp_window_name) + "_" + std::to_string(m_win32_class_counter);
    m_win32_class_counter++;

    window_class.cbSize        = sizeof(WNDCLASSEX);
    window_class.style         = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc   = WindowEventHandler;
    window_class.cbClsExtra    = 0;
    window_class.cbWndExtra    = 0;
    window_class.hInstance     = m_win32_instance;
    window_class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    window_class.lpszMenuName  = nullptr;
    window_class.lpszClassName = m_win32_class_name.c_str();
    window_class.hIcon         = LoadIcon  (nullptr, IDI_APPLICATION);
    window_class.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    window_class.hIconSm       = LoadIcon  (nullptr, IDI_WINLOGO);

    // Registering the class
    if(RegisterClassEx(&window_class) == 0)
    {
        throw std::runtime_error("Unable to register the window class.");
    }

    DWORD ex_style = WS_EX_APPWINDOW;
    DWORD style    = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

    RECT window_rect
    {
        0,
        0,
        LONG(m_window_width),
        LONG(m_window_height)
    };

    // Adjusting the rect for the surface
    AdjustWindowRectEx(&window_rect, style, FALSE, ex_style);

    m_win32_handle = CreateWindowEx
    (
        ex_style,
        m_win32_class_name.c_str(),
        mp_window_name,
        style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        window_rect.right  - window_rect.left,
        window_rect.bottom - window_rect.top,
        nullptr,
        nullptr,
        m_win32_instance,
        this
    );

    if(!m_win32_handle)
    {
        throw std::runtime_error("Unable to create the os window.");
    }

    SetWindowLongPtrW  (m_win32_handle, GWLP_USERDATA, (LONG_PTR)this);
    SetForegroundWindow(m_win32_handle);
    ShowWindow         (m_win32_handle, SW_SHOW);
    SetFocus           (m_win32_handle);
}

void IWindow::ReleaseOS()
{
    DestroyWindow  (m_win32_handle);
    UnregisterClass(m_win32_class_name.c_str(), m_win32_instance);
}

void IWindow::UpdateOS()
{
    MSG message;
    if(PeekMessage(&message, m_win32_handle, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&message);
        DispatchMessage (&message);
    }
}

} // !namespace

} // !namespace

#endif