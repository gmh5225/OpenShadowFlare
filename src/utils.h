#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <Windows.h>
#include <cstdint>
#include "utils.h"

/**
* LOAD_AND_EXECUTE_ORIGINAL_FUNC Macro
*
* This macro abstracts the repeated steps of loading a DLL, retrieving a function
* address using its mangled name, executing the function, and then releasing the DLL.
*
* @param dllName: Name of the original DLL to load.
* @param funcType: Type definition (typedef) of the function pointer.
* @param funcNameMangled: Mangled name of the function to retrieve and execute.
* @param ... : Variable arguments that represent parameters to be passed to the function.
*
* If there's a failure in loading the DLL or retrieving the function address,
* it prints an error message and returns from the current function.
*
* Example usage:
* LOAD_AND_EXECUTE_ORIGINAL_FUNC(
*     "o_RKC_FONTMAKER.dll",
*     drawDoubleFontPtr,
*     "?DrawDoubleFont@RKC_FONTMAKER@@QAEHPAUHDC__@@PAE@Z",
*     self, hdc, param
* );
*/
#define LOAD_AND_EXECUTE_ORIGINAL_FUNC(dllName, funcType, funcNameMangled, ...) do {     \
    HINSTANCE o_dll = LoadLibrary(TEXT(dllName));                                        \
    if (!o_dll) {                                                                        \
        printf("Failed to load %s with error code: 0x%x\n", dllName, GetLastError());    \
        return;                                                                          \
    }                                                                                    \
    funcType o_func = (funcType)GetProcAddress(o_dll, funcNameMangled);                  \
    if (!o_func) {                                                                       \
        printf("Failed to find %s function in %s with error code: 0x%x\n",               \
               #funcType, dllName, GetLastError());                                      \
        FreeLibrary(o_dll);                                                              \
        return;                                                                          \
    }                                                                                    \
    o_func(__VA_ARGS__);                                                                 \
    FreeLibrary(o_dll);                                                                  \
} while (0)

#endif