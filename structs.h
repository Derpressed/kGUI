#ifndef STRUCTS_H
#define STRUCTS_H

// Code must generate a parent window first
// struct for parent window
typedef struct {
    // check validity of our process
    int valid;
    // pointer to the handle of our program
    HINSTANCE hInstance;
    // class name of our main window
    LPCWSTR CLASS_NAME;
    // only needs lpfnWndProc, hInstance, lpszClassName
    WNDCLASSW wc;
    // an array for all our elements within this process
} kGUI;

// parameters for making any window function
typedef struct {
    DWORD     exStyle; // extended windows styles
    LPCWSTR   CLASS_NAME; // class name of the program
    LPCWSTR   WINDOW_NAME; // window name of this object
    DWORD     style; // windows styles
    int       x; // position that this window will pop up
    int       y; // position that this window will pop up
    int       width; // the width that this window will pop up
    int       length; // the length that this window will pop up
    HWND      parent; // parent handle window
    HMENU     menu; // menu
    HINSTANCE hInstance; // handle instance of our whole program
    LPVOID    lpParam; // usually NULL

    HWND hwnd;
} kWnd;

// interrupt function for Windows
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// when initiallizing your process, takes a string to be called a class
// returns your process struct
kGUI procK(LPCWSTR kGUIClassName);

// when initializing your main window, takes the process struct and window name
// returns your window struct
kWnd wndK(kGUI *parentClass, LPCWSTR wndName);

// when running your window to be displayed, takes the window struct
// returns an int -> 0 = valid, 1 = invalid
int showK(kWnd* kWndMain);
#endif
