#pragma once
#include <Windows.h>

struct offsets
{
	uintptr_t cURL = 0x39072E0; // sub_7DDA72E0, mov [rsp+arg_8], edx [DUMP: 11/07/2022]
	uintptr_t UAC = 0x1A7B9F; // call, mov, xor (RVA: 2) if patternscan [DUMP: 11/07/2022]

}; offsets* fnoffsets = new offsets( );