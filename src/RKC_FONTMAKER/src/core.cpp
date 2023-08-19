#include <iostream>
#include <Windows.h>
#include <cstdint>

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
        self->member1 = 0;
        self->member2 = 0;
        self->member3 = 0;
        self->member4 = 0;
        self->member5 = 0;
        self->member6 = 0;
        self->member7 = 0;
    }
}