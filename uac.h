// pure meme

#pragma once

#include <Windows.h>
#include <cstdint>

void (*uac_h) (void** base_address, unsigned char v1, unsigned char v2);
void UAC(void** base_address, unsigned char v1, unsigned char v2)
{
    MEMORY_BASIC_INFORMATION memoryinfo;
    uint8_t* uac_secured = reinterpret_cast<uint8_t*>( 0x7A2F1D ); // sub_7DDA79E0, mov [rsp+arg_0], rbx [DUMP: 11/07/2022]
    DWORD oldprotect;

    unsigned char shellcode[ ] =
    {
      0xAB, 0x34, 0xFF, 0x6A, 0xC9, 0x12, 0x8D, 0x5E, 0x71, 0x2B,
      0xE5, 0x98, 0x45, 0xA3, 0xD7, 0x6F, 0x28, 0x56, 0x9A, 0xC1,
      0xB0, 0xF2, 0x7D, 0x83, 0x1E, 0x59, 0x4C, 0xE2, 0xAF, 0xD1,
      0x6B, 0x70
    };

    if ( VirtualProtect( uac_secured, sizeof( shellcode ), PAGE_EXECUTE_READWRITE, &oldprotect ))
    {
        // omg ud memory copy ??!!
        memcpy( uac_secured, shellcode, sizeof( shellcode ));

        if (VirtualQuery( uac_secured, &memoryinfo, sizeof( memoryinfo )) == sizeof( memoryinfo ))
        {
            *base_address = memoryinfo.BaseAddress;
            //std::cout << E("[+] Patched UAC base address: ") << *base_address << std::endl;
        }

        // what if i keep new region protection :troll:
        VirtualProtect( uac_secured, sizeof( shellcode ), oldprotect, &oldprotect );
    }

    return uac_h(base_address, v1, v2);
}
