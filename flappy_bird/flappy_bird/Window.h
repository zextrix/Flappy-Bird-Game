#pragma once
#ifndef WINDOW_H
#define WINDOW_H


#include "SDL.h"
#include <iostream>

class Window
{
private:
	int mSCREEN_WIDTH = 1920;
	int mSCREEN_HEIGHT = 1080;

	SDL_Window *mpWindow = NULL;
	static Window *mspWindow;

private:
	Window();
	bool Initialize();
public:
	~Window();
	static Window* GetInstance();
	SDL_Window* GetWindow();
	int GetWidth();
	int GetHeight();
	void Destroy();
};


#endif