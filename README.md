# kGUI
A small GUI module tailored for me to be used through C

## Information
### `typedef struct kGUI`
|type|Parameter|Description|
|:-------------|:--------------|:------------|
|`int`|`valid`||
|`HINSTANCE`|`hInstance`||
|`LPCWSTR`|`CLASS_NAME`||
|`WNDCLASSW`|`wc`||

    
### `typedef struct kWnd`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`DWORD`|`exStyle`||
|`LPCWSTR`|`CLASS_NAME`||
|`LPCWSTR`|`WINDOW_NAME`||
|`DWORD`|`style`||
|`int`|`x`||
|`int`|`y`||
|`int`|`width`||
|`int`|`length`||
|`HWND`|`parent`||
|`HMENU`|`menu`||
|`HINSTNACE`|`hInstance`||
|`LPVOID`|`lpParam`||
|`HWND`|`hwnd`||

### `procK(LPCWSTR kGUIClassName);`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`LPCWSTR`|`kGUIClassName`||

**Returns:** `kGUI` - struct of process


### `wndK (function);`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`kGUI`|`*parentClass`||
|`LPCWSTR`|`wndName`||

**Returns:** `kWnd` - struct of window

### `showK (function);`
|type|Parameter|Description|
|:-------------|:--------------|:--------------|
|`kWnd`|`*kWndMain`||

**Returns:** `int` - `0` if process is valid, else `1`
