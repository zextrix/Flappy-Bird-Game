#include "stdafx.h"
#include "TextureManager.h"


TextureManager *TextureManager::mspTextureManager = nullptr;


TextureManager::TextureManager(){}


TextureManager::~TextureManager()
{
	for ( std::pair< std::string, SDL_Texture*> texture : mTextureCollections)
		SDL_DestroyTexture(texture.second);
	this->mTextureCollections.clear();
	IMG_Quit();
}


bool TextureManager::Initialize()
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << "Error @TextureManager -> Initialize : " << IMG_GetError();
		return false;
	}

	return true;
}

TextureManager* TextureManager::GetInstance()
{
	if (mspTextureManager == nullptr)
	{
		mspTextureManager = new TextureManager();
		if (!mspTextureManager->Initialize())
		{
			mspTextureManager->Destroy();
			return nullptr;
		}
	}

	if (mspTextureManager == nullptr) std::cout << "Error @TextureManager -> GetInstance\n";
	
	return mspTextureManager;
}


SDL_Texture* TextureManager::GetTexture(std::string image)
{
	if (this->mTextureCollections[image] == nullptr)
	{
		//load
		std::string path = "assets\\" + image;

		SDL_Texture* new_texture = nullptr;
		SDL_Surface* loaded_surface = nullptr;

		//Load image at specified path		
		loaded_surface = IMG_Load(path.c_str());
		if (loaded_surface == nullptr)
		{
			std::cout << "Error @TextureManager -> GetTexture -> SDL_image : " << path.c_str() << " " << IMG_GetError(); 
		}
		else
		{
			//Create texture from surface pixels
			new_texture = SDL_CreateTextureFromSurface(Render::GetInstance()->GetRenderer(), loaded_surface);
			if (new_texture == nullptr)
			{
				std::cout << "Error @TextureManager -> GetTexture -> SDL_CreateTextureFromSurface : " << path.c_str() << " " << SDL_GetError();
			}
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loaded_surface);

		mTextureCollections[image] = new_texture;
	}

	return mTextureCollections[image];
}


void TextureManager::Destroy()
{
	delete mspTextureManager;
	mspTextureManager = nullptr;
}