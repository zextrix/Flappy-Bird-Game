// flappy_bird.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Engine E;
	if (E.Initialize())
	{	
		E.GameLoop();
	}
	E.Destroy();
	return 0;
}

