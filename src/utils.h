#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <Windows.h>
#include <cstdint>
#include "utils.h"

template <typename RetType, typename... Args>
RetType CallFunctionInDLL(const char* dllName, const char* funcName, Args... args) {
    // Load the DLL into memory
    HINSTANCE loadedDll = LoadLibraryA(dllName);

    // Check if the DLL loaded successfully
    if (!loadedDll) {
        printf("Failed to load %s with error code: 0x%x\n", dllName, GetLastError());
        if constexpr (!std::is_void<RetType>()) {
            return static_cast<RetType>(0);
        } else {
            return;
        }
    }

    // Get the address of the function from the loaded DLL
    typedef RetType(WINAPI* FuncType)(Args...);
    FuncType funcPtr = (FuncType)GetProcAddress(loadedDll, funcName);

    // Check if we successfully retrieved the address of the function
    if (!funcPtr) {
        printf("Failed to find %s function in %s with error code: 0x%x\n", funcName, dllName, GetLastError());
        FreeLibrary(loadedDll);
        if constexpr (!std::is_void<RetType>()) {
            return static_cast<RetType>(0);
        } else {
            return;
        }
    }

    // Call the function using the function pointer
    if constexpr (!std::is_void<RetType>()) {
        RetType result = funcPtr(args...);
        FreeLibrary(loadedDll);
        return result;
    } else {
        funcPtr(args...);
        FreeLibrary(loadedDll);
    }
}



#endif // UTILS_H