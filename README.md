# kGUI
A small GUI module tailored for me to be used through C

## Information
### `typedef struct kGUI`
|type|Parameter|Description|
|:-------------|:--------------|:------------|
|`int`|`valid`|`integer check whether function returns valid`|
|`HINSTANCE`|`hInstance`|`Handle of an instance of a window`|
|`LPCWSTR`|`CLASS_NAME`|`Long Pointer Char, needed for what the website will be referred to in code`|
|`WNDCLASSW`|`wc`|`Built-in class by windows, check API`|

    
### `typedef struct kWnd`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`DWORD`|`exStyle`|`Parameter for the type of window, check Windows API`|
|`LPCWSTR`|`CLASS_NAME`|`Long Pointer Char, Class name reference`|
|`LPCWSTR`|`WINDOW_NAME`|`Long Pointer Char, Window name reference`|
|`DWORD`|`style`|`Main parameter for the type of window, check Windows API`|
|`int`|`x`|`Absolute width position of window within screen pixels (0 = left)`|
|`int`|`y`|`Absolute height position of window within screen pixels (0 = top)`|
|`int`|`width`|`Width of window based on screen pixels`|
|`int`|`length`|`length of window based on screen pixels`|
|`HWND`|`parent`|`Handle of a child window (usage for any extra children windows)`|
|`HMENU`|`menu`|`Handle for a menu, often left NULL`|
|`HINSTNACE`|`hInstance`|`Handle to an instance of a class, check Windows API`|
|`LPVOID`|`lpParam`|`NULL`|
|`HWND`|`hwnd`|`Handle to a window in the case of any child windows`|

### `procK(LPCWSTR kGUIClassName);`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`LPCWSTR`|`kGUIClassName`|`Long Poitner Char, Window class name to referred in code`|

**Returns:** `kGUI` - struct of process


### `wndK(kGUI *parentClass, LPCWSTR wndName);`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`kGUI`|`*parentClass`|`string, used for class reference`|
|`LPCWSTR`|`wndName`|`Window name string`|

**Returns:** `kWnd` - struct of window

### `showK(kWnd *kWndMain);`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`kWnd`|`*kWndMain`|`Window name string, referred in code`|

**Returns:** `int` - `0` if process is valid, else `1`

<h2>
    Installation/Usage
</h2>

<p>
    To be reliably used within every machine, MacOS and any other operating system's API will be needed in future updates.
</p>
<p>
    Functionality is limited to Window Creation, code will be updated once all functionality is built in
</p>
