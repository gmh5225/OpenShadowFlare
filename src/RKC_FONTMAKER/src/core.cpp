#include <iostream>
#include <Windows.h>
#include <cstdint>
#include "utils.h"

class RKC_FONTMAKER {
    // Based on the offsets and the sizeof(undefined4) which is 4 bytes.
    // We'll assume these are all 32-bit integers for now.
public:
    int32_t member1;   // Offset 0x08
    int32_t member2;   // Offset 0x0C
    int32_t member3;   // Offset 0x10
    int32_t member4;   // Offset 0x14
    // Skipping offset 0x18 as it's not initialized or used here
    int32_t member5;   // Offset 0x1C
    int32_t member6;   // Offset 0x20
    int32_t member7;   // Offset 0x24

};

// Pointers to the original functions
// These can be deleted once the DLL is entirely rewritten
typedef VOID(WINAPI* deconstructorPtr)(RKC_FONTMAKER* self);
typedef VOID(WINAPI* createDIBPtr)(RKC_FONTMAKER* self, HDC* hdc);
typedef VOID(WINAPI* drawDoubleFontPtr)(RKC_FONTMAKER* self, HDC* hdc, unsigned char* param);

extern "C" {
    void __thiscall RKC_FONTMAKER_constructor(RKC_FONTMAKER* self)
    {
        self->member1 = 0;
        self->member2 = 0;
        self->member3 = 0;
        self->member4 = 0;
        self->member5 = 0;
        self->member6 = 0;
        self->member7 = 0;
    }

    void __thiscall RKC_FONTMAKER_deconstructor(RKC_FONTMAKER* self)
    {
        LOAD_AND_EXECUTE_ORIGINAL_FUNC(
            "o_RKC_FONTMAKER.dll",
            deconstructorPtr,
            "??1RKC_FONTMAKER@@QAE@XZ",
            self
        );
    }

    void __thiscall CreateDIB(RKC_FONTMAKER* self, HDC* hdc)
    {
        LOAD_AND_EXECUTE_ORIGINAL_FUNC(
            "o_RKC_FONTMAKER.dll",
            createDIBPtr,
            "?CreateDIB@RKC_FONTMAKER@@QAEHPAUHDC__@@@Z",
            self, hdc
        );
    }

    void __thiscall DrawDoubleFont(RKC_FONTMAKER* self, HDC* hdc, unsigned char* ucharParam)
    {
        LOAD_AND_EXECUTE_ORIGINAL_FUNC(
            "o_RKC_FONTMAKER.dll",
            drawDoubleFontPtr,
            "?DrawDoubleFont@RKC_FONTMAKER@@QAEHPAUHDC__@@PAE@Z",
            self, hdc, ucharParam
        );
    }
}