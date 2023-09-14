#include "framework.h"
#include "pscan.h"
#include "uac.h"

auto entry( ) -> VOID
{
    AllocConsole( );
    SetConsoleTitleA(E("fortnite storm ssl 2022 - made by roka (@vpointer)"));
    freopen("CONOUT$", "w", stdout);

    printf( E("[+] entry: %p\n", entry ));

    // minhook very pro hookar!!
    auto mh = MH_Initialize( );
    if (mh != MH_OK)
    { 
        printf( E( "[-] could not load minhook. %p\n", mh ));
        std::cin.get( );
    }

    printf( E( "[+] MinHook loaded: %p\n", mh ));

    MH_CreateHook(( LPVOID )GetOffset( fnoffsets->cURL ), curl_mh_hook, (void**)&_curl_easy_setopt );
    MH_EnableHook(( LPVOID )GetOffset( fnoffsets->cURL ));

    MH_CreateHook(( LPVOID )GetOffset( fnoffsets->UAC ), UAC, (void**)&uac_h );
    MH_EnableHook(( LPVOID )GetOffset( fnoffsets->UAC ));

    std::cin.get( );
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    if ( ul_reason_for_call == 1 )
    {
        entry( );
    }
}