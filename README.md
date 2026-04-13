### kGUI
A small GUI module tailored for me to be used through C

### INFORMATION

kGUI 
typedef struct that has the following properties:
int valid
HINSTANCE hInstance
LPCWSTR CLASS_NAME
WNDCLASSW wc

kWnd 
typedef struct that has the following properties:
DWORD exStyle
LPCWSTR CLASS_NAME
LPCWSTR WINDOW_NAME
DWORD style
int x
int y
int width
int length
HWND parent
HMENU menu
HINSTANCE hInstance
LPVOID lpParam
HWND hwnd

## FUNCTIONS
procK
function that takes L"string"
returns kGUI struct

wndK
function that takes (kGUI struct, L"string")
returns kWnd struct

showK
function that takes (kWnd struct)
return int valid
