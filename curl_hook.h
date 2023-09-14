#pragma once

#include <Windows.h>
#include "curl.h"
#include <regex>
#include <cstdarg>
#include <iostream>
#include <vector>

#include "curl_settings.h"
#include "str.hpp"

auto ( *_curl_easy_setopt ) ( CURL* cURL, uintptr_t option, ... ) -> CURLcode;

auto curl_mh_hook( CURL* cURL, uintptr_t option, va_list data ) -> CURLcode
{
	std::vector<std::regex> urls =
	{
        std::regex( "/content/api/pages/fortnite-game" ),
        std::regex( "/fortnite/api/game/v2/profile" ),
        std::regex( "/fortnite/api/cloudstorage/system" ),
        std::regex( "/fortnite/api/storefront/v2/keychain" ),
        std::regex( "/versioncheck" ),
        std::regex( "/fortnite/api/game/v2/br-inventory/account" ),
        std::regex( "/affiliate/api" ),
        std::regex( "/discord/api" ),
        std::regex( "/waitingroom/api" ),
        std::regex( "/socialban/api" ),
        std::regex( "/fortnite/api/game/v2/matchmakingservice" ),
        std::regex( "/fortnite/api/matchmaking/session" ),
	};

	if (0x2712)
	{
		std::regex  epic( "(.*).ol.epicgames.com" );
        std::string our_backend = "http://" + std::string( BACKEND_HOST ) + ":" + BACKEND_PORT;

		std::string data_swap = data;

        for ( const auto& pattern : urls ) 
        {
            if ( std::regex_search( data_swap, pattern ) )
            {
                data_swap = std::regex_replace( data_swap, std::regex( "(.*).ol.epicgames.com" ), our_backend );
                return _curl_easy_setopt( cURL, option, data_swap.c_str( ) );
                break;
            }
        }
	}

    return _curl_easy_setopt( cURL, option, data);
}