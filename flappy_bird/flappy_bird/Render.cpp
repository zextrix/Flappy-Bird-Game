#include "Render.h"


Render *Render::mspInstance = NULL;

Render::Render()
{
	this->mpRenderer = SDL_CreateRenderer(Window::GetInstance()->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
	if (this->mpRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	SDL_SetRenderDrawColor(this->mpRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}


Render::~Render()
{
	SDL_DestroyRenderer(mpRenderer);
}


Render* Render::GetInstance()
{
	if (mspInstance == NULL)
	{
		mspInstance = new Render();
	}

	return mspInstance;
}


SDL_Renderer* Render::GetRenderer()
{
	return this->mpRenderer;
}


void Render::RenderDisplay()
{
	SDL_RenderPresent(this->mpRenderer);
}


void Render::Clear()
{
	SDL_SetRenderDrawColor(this->mpRenderer, 0, 0, 0, 255);
	SDL_RenderClear(this->mpRenderer);
}


void Render::Destroy()
{
	delete mspInstance;
	mspInstance = nullptr;
}