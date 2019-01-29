#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Vector2D.h"
#include "Render.h"
#include "TextureManager.h"

class Texture
{
	SDL_Texture *mpTexture;
	short mFrameCount;
	short mCurrentFrameNumber;
	Vector2D mDimension;
public:
	Texture();
	~Texture();

	void Load(std::string image);
	void SetFrameCount(short frameCount);
	void Update(float deltaTime);
	//void SetSdlTexture(SDL_Texture *psdlTexture);
	//void FreeSdlTexture();
	//SDL_Texture* GetSdlTexture();
	void Destroy();
	void Render(Vector2D& position, Vector2D& dimension);
};

#endif