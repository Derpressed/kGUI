#include <windows.h>

// Code must generate a parent window first
// struct for parent window
typedef struct {
    // check validity of our process
    int valid;
    // pointer to the handle of our program
    HINSTANCE hInstance;
    // class name of our main window
    const char* CLASS_NAME;
    // only needs lpfnWndProc, hInstance, lpszClassName
    WNDCLASS wc;
    // an array for all our elements within this process
} kGUI;

// parameters for making any window function
typedef struct {
    DWORD     exStyle, // extended windows styles
    LPCWSTR*  CLASS_NAME, // class name of the program
    LPCWSTR*  WINDOW_NAME, // window name of this object
    DWORD     style, // windows styles
    int       x, // position that this window will pop up
    int       y, // position that this window will pop up
    int       width, // the width that this window will pop up
    int       length, // the length that this window will pop up
    HWND      parent, // parent handle window
    HMENU     menu, // menu
    HINSTANCE hInstance, // handle instance of our whole program
    LPVOID    lpParam // usually NULL
} kWnd;

// this function is called when we create a class
kGUI initK(const char* kGUIClassName) {
    kGUI kMaster = {0};

    // get our handle instance for program
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // init wc parameters (check if we need to change anything else)
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = kGUIClassName;
    
    // declaring our struct (this will be a passed along)
    kMaster.valid = RegisterClass(&wc); // returns 0 if fails
    kMaster.valid = valid;
    kMaster.hInstance = hInstance;
    kMaster.CLASS_NAME = kGUIClassName;
    kMaster.wc = wc;
    
    return kMaster;
}

// this function is called when we create a process window
HWND wndK(kGUI* parentClass, const char* wndName) {
    kWnd wndMaster = {0};

    // change later
    DWORD defaultStyle = WS_OVERLAPPEDWINDOW;

    wndMaster.exStyle = 0,
    wndMaster.CLASS_NAME = parentClass->CLASS_NAME,
    wndMaster.WINDOW_NAME = wndName,
    wndMaster.style = defaultStyle,
    wndMaster.x = 0,
    wndMaster.y = 0,
    wndMaster.width = 


    return wndMaster;
}

int showk() {
    int valid = 0;

    return valid;
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
    
    // give us the pointer to the handle of our own process
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // name our class process "SimpleWindow"
    const char CLASS_NAME[] = "SimpleWindow";


    WNDCLASS wc = {0};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Hello Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 200,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) return 1;

    // Textbox (EDIT control)
    CreateWindowEx(
        0,
        "EDIT",
        "Hello World",
        WS_CHILD | WS_VISIBLE,
        0, 0, 100, 1,
        hwnd,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, SW_SHOW);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}