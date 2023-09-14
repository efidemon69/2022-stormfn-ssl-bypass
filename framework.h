#pragma once

#include <windows.h>
#include <iostream>

#include "str.hpp"
#include "minhook.h"
#include "curl_hook.h"
#include "offsets.h"
#include "exithook.h"

#pragma warning( disable : 4996 )

uintptr_t GetOffset( uintptr_t offset )
{
    return reinterpret_cast<uintptr_t>(GetModuleHandleA( 0 )) + offset;
}