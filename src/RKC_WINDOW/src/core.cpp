#include <iostream>
#include <Windows.h>
#include <cstdint>

class RKC_WINDOW {
public:
    int member1;         // or could be a pointer
    int member2;
    RKC_WINDOW* m_hWnd;     // this[8], seems to be a self reference or pointer to similar type

    // The space between member3 and memberArray is not described.
    // It could be empty, or there could be other members.
    int memberArray[10]; // Starting from offset 0x508

    int member4;         // Starting from offset 0x530
    int member5;
    int member6;
    int member7;
    int member8;
    int member9;
    int member10;
    int member11;
};

// Pointers to the original functions
// These can be deleted once the DLL is entirely rewritten
typedef VOID(WINAPI* hScrollPtr)(RKC_WINDOW* wnd, uint32_t param1, uint32_t param2);
typedef VOID(WINAPI* vScrollPtr)(RKC_WINDOW* wnd, uint32_t param1, uint32_t param2);
typedef VOID(WINAPI* resizePtr)(RKC_WINDOW* wnd);
typedef VOID(WINAPI* showPtr)(RKC_WINDOW* wnd);

extern "C" {
    void __thiscall RKC_Window_constructor(RKC_WINDOW* wnd)
    {
        wnd->member1 = 0;
        wnd->member2 = 0;
        wnd->m_hWnd = 0x0;
        *(wnd->memberArray) = 0x0;

        for (int i = 0; i < 10; i++) {
            wnd->memberArray[i] = 0;
        }

        wnd->member4 = 0;
        wnd->member5 = 0;
        wnd->member6 = 0;
        wnd->member7 = 0;
        wnd->member8 = 0;
        wnd->member9 = 0;
        wnd->member10 = 0;
        wnd->member11 = 0;
    }

    void __thiscall RKC_Window_deconstructor(RKC_WINDOW* wnd)
    {
        return;
    }

    RKC_WINDOW& __thiscall EqualsOperator(RKC_WINDOW* wnd, const RKC_WINDOW& lhs)
    {
        wnd->m_hWnd = lhs.m_hWnd;
        return *wnd;
    }

    void __thiscall HScroll(RKC_WINDOW* wnd, uint32_t param1, uint64_t param2)
    {
        // Load the original (renamed) DLL into memory
        HINSTANCE o_window_Dll = LoadLibrary(TEXT("o_RKC_WINDOW.dll"));

        // Check if the original DLL loaded successfully
        if (!o_window_Dll) {
            // Print an error message if failed to load, showing the error code
            printf("Failed to load o_RKC_WINDOW.dll with error code: 0x%x\n", GetLastError());
            return;
        }

        // Get the address of the original HScroll function from o_RKC_WINDOW.dll
        hScrollPtr o_hScroll_func = (hScrollPtr)GetProcAddress(o_window_Dll, "?HScroll@RKC_WINDOW@@QAEXIJ");

        // Check if we successfully retrieved the address of the original function
        if (!o_hScroll_func) {
            // Print an error message if failed to retrieve, showing the error code
            printf("Failed to find HScroll function in o_RKC_WINDOW.dll with error code: 0x%x\n", GetLastError());
            return;
        }

        // Call the original function using our function pointer
        o_hScroll_func(wnd, param1, param2);

        // Free the loaded original dll from memory. Important to release resources!
        FreeLibrary(o_window_Dll);

        return;
    }

    void __thiscall VScroll(RKC_WINDOW* wnd, uint32_t param1, uint64_t param2)
    {
        // Load the original (renamed) DLL into memory
        HINSTANCE o_window_Dll = LoadLibrary(TEXT("o_RKC_WINDOW.dll"));

        // Check if the original DLL loaded successfully
        if (!o_window_Dll) {
            // Print an error message if failed to load, showing the error code
            printf("Failed to load o_RKC_WINDOW.dll with error code: 0x%x\n", GetLastError());
            return;
        }

        // Get the address of the original function from the original dll
        vScrollPtr o_vScroll_func = (vScrollPtr)GetProcAddress(o_window_Dll, "?VScroll@RKC_WINDOW@@QAEXIJ@Z");

        // Check if we successfully retrieved the address of the original function
        if (!o_vScroll_func) {
            // Print an error message if failed to retrieve, showing the error code
            printf("Failed to find VScroll function in o_RKC_WINDOW.dll with error code: 0x%x\n", GetLastError());
            return;
        }

        // Call the original function using our function pointer
        o_vScroll_func(wnd, param1, param2);

        // Free the loaded original dll from memory. Important to release resources!
        FreeLibrary(o_window_Dll);

        return;
    }

    void __thiscall Resize(RKC_WINDOW* wnd)
    {
        // Load the original (renamed) DLL into memory
        HINSTANCE o_window_Dll = LoadLibrary(TEXT("o_RKC_WINDOW.dll"));

        // Check if the original DLL loaded successfully
        if (!o_window_Dll) {
            // Print an error message if failed to load, showing the error code
            printf("Failed to load o_RKC_WINDOW.dll with error code: 0x%x\n", GetLastError());
            return;
        }

        // Get the address of the original function from the original dll
        showPtr o_show_func = (showPtr)GetProcAddress(o_window_Dll, "?Show@RKC_WINDOW@@QAEXH@z");

        // Check if we successfully retrieved the address of the original function
        if (!o_show_func) {
            // Print an error message if failed to retrieve, showing the error code
            printf("Failed to find VScroll function in o_RKC_WINDOW.dll with error code: 0x%x\n", GetLastError());
            return;
        }

        // Call the original function using our function pointer
        o_show_func(wnd);

        // Free the loaded original dll from memory. Important to release resources!
        FreeLibrary(o_window_Dll);

        return;
    }

    void __thiscall Show(RKC_WINDOW* wnd, int param_1)
    {
        // Load the original (renamed) DLL into memory
        HINSTANCE o_window_Dll = LoadLibrary(TEXT("o_RKC_WINDOW.dll"));

        // Check if the original DLL loaded successfully
        if (!o_window_Dll) {
            // Print an error message if failed to load, showing the error code
            printf("Failed to load o_RKC_WINDOW.dll with error code: 0x%x\n", GetLastError());
            return;
        }

        // Get the address of the original function from the original dll
        resizePtr o_resize_func = (resizePtr)GetProcAddress(o_window_Dll, "??Resize@RKC_WINDOW@@QAEX");
    }
}



bool __stdcall DllMain(LPVOID, std::uint32_t call_reason, LPVOID)
{
    return true;
}