#pragma once
#ifndef RENDER_H
#define RENDER_H


#include "SDL.h"
#include "Window.h"
#include <iostream>


class Render
{
private:
	SDL_Renderer *mpRenderer = NULL;
	static Render *mspInstance;

private:
	Render();
	~Render();
public:
	static Render* GetInstance();
	SDL_Renderer* GetRenderer();
	void RenderDisplay();
	void Clear();
	void Destroy();
};

#endif