#pragma once

// omgggg didnt include this???!!!!!!
// for niggers who will paste this, include "PushWidget & UnsafeEnvironmentPopupAddress"

void ( *RequestExitWithStatus ) ( bool call, unsigned char ret );
void RequestExitWithStatusHook( bool call, unsigned char ret )
{
	printf(E( "RequestExitWithStatus Call : %i\n" ), call, ret );
}