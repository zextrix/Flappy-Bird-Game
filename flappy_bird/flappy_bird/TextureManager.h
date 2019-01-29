#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "Render.h"

class TextureManager
{

private:
	std::map<std::string, SDL_Texture*> mTextureCollections;
	static TextureManager *mspTextureManager;

private:
	TextureManager();
	bool Initialize();
public:
	~TextureManager();
	static TextureManager* GetInstance();
	SDL_Texture* GetTexture(std::string);
	void Destroy();
};

#endif