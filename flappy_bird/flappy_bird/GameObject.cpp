#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	this->mTexture.Destroy();
}


Vector2D GameObject::GetPosition()
{
	return this->mPosition;
}


Vector2D GameObject::GetDimension()
{
	return this->mDimension;
}


Texture& GameObject::GetTexture()
{
	return this->mTexture;
}


void GameObject::SetPosition(Vector2D position)
{
	this->mPosition = position;
}


void GameObject::SetDimension(Vector2D dimension)
{
	this->mDimension = dimension;
}


void GameObject::SetPositionAndDimension(Vector2D position, Vector2D dimension)
{
	this->mPosition = position;
	this->mDimension = dimension;
}