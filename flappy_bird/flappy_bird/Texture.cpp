#include "Texture.h"


Texture::Texture()
{
	this->mpTexture = NULL;
	mCurrentFrameNumber = 0;
	mFrameCount = 1;
}


Texture::~Texture(){}


void Texture::Load(std::string image)
{
	this->mpTexture = TextureManager::GetInstance()->GetTexture(image);
	int w, h;
	SDL_QueryTexture(this->mpTexture, NULL, NULL, &w, &h);
	mDimension = Vector2D(w,h);
}


void Texture::SetFrameCount(short frameCount)
{
	mFrameCount = frameCount;
}
/*
void Texture::SetSdlTexture(SDL_Texture *psdlTexture)
{
	this->mpTexture = psdlTexture;
}


void Texture::FreeSdlTexture()
{
	SDL_DestroyTexture(this->mpTexture);
}


SDL_Texture* Texture::GetSdlTexture()
{
	return this->mpTexture;
}*/


void Texture::Destroy(){}


void Texture::Update(float deltaTime)
{
	mCurrentFrameNumber = (++mCurrentFrameNumber)%mFrameCount;
}


void Texture::Render(Vector2D &position, Vector2D& dimension)
{
	SDL_Rect partial_clip = { (mDimension.GetX() / mFrameCount)*mCurrentFrameNumber, 0, mDimension.GetX() / mFrameCount, mDimension.GetY() };
	SDL_Rect view_port = { position.GetX(), position.GetY(), dimension.GetX(), dimension.GetY() };
	SDL_RenderCopy(Render::GetInstance()->GetRenderer(), this->mpTexture, &partial_clip, &view_port);
}
