#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H


#include "Texture.h"
#include "Vector2D.h"
#include "Listener.h"


class GameObject :
	public Listener
{
private:
	Texture mTexture;
	Vector2D mPosition;
	Vector2D mDimension;

public:
	GameObject();
	~GameObject();

	//pure virtual functions
	virtual void Initialize() = 0;
	virtual void Update(float deltatime) = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;

	//get function
	Vector2D GetPosition();
	Vector2D GetDimension();
	Texture& GetTexture();

	//set functions
	void SetPosition(Vector2D position);
	void SetDimension(Vector2D dimension);
	void SetPositionAndDimension(Vector2D position, Vector2D dimension);
};

#endif