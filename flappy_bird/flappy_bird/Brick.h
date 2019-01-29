#pragma once
#ifndef BRICK_H
#define BRICK_H


#include "GameObject.h"
#include "PlayState.h"

class Brick :
	public GameObject
{
private:
	Vector2D mSpeed;

private:
	void IsCollision();

public:
	Brick(Vector2D position);
	~Brick();

	//pure virtual functions
	void Initialize();
	void Update(float deltatime);
	void Render();
	void Destroy();
	bool HandleEvent(Event *_event);
};


#endif