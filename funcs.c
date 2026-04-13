#include <windows.h>
#include "structs.h"
#include <stdio.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

// this function is called when we create a class (kGUI)
kGUI procK(LPCWSTR kGUIClassName) {
    kGUI kMaster = {0};

    // get our handle instance for program
    HINSTANCE hInstance = GetModuleHandleW(NULL);

    // init wc parameters (check if we need to change anything else)
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = kGUIClassName;
    
    // declaring our struct (this will be a passed along)
    kMaster.valid = RegisterClassW(&wc); // returns 0 if fails
    kMaster.hInstance = hInstance;
    kMaster.CLASS_NAME = kGUIClassName;
    kMaster.wc = wc;
    
    return kMaster;
}

// this function is called when we create a process window
kWnd wndK(kGUI *parentClass, LPCWSTR wndName) {
    kWnd wndMaster = {0};

    wndMaster.exStyle = 0;
    wndMaster.CLASS_NAME = parentClass->CLASS_NAME;
    wndMaster.WINDOW_NAME = wndName;
    wndMaster.style = WS_OVERLAPPEDWINDOW;
    wndMaster.x = 0;
    wndMaster.y = 0;
    wndMaster.width = 500;
    wndMaster.length = 200;
    wndMaster.parent = NULL;
    wndMaster.menu = NULL;
    wndMaster.hInstance = parentClass->hInstance;
    wndMaster.lpParam = NULL;

    return wndMaster;
}

int showK(kWnd* kWndMain) {
    int valid = 0;

    // initializing our struct here because we can change it later
    kWndMain->hwnd = CreateWindowExW(
        kWndMain->exStyle,
        kWndMain->CLASS_NAME,
        kWndMain->WINDOW_NAME,
        kWndMain->style,
        kWndMain->x,
        kWndMain->y,
        kWndMain->width,
        kWndMain->length,
        kWndMain->parent,
        kWndMain->menu,
        kWndMain->hInstance,
        kWndMain->lpParam
    );


    ShowWindow(kWndMain->hwnd, SW_SHOW);

    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return valid;
}
