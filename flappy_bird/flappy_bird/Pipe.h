#pragma once
#ifndef PIPE_H
#define PIPE_H


#include "GameObjects.h"
class Brick;


class Pipe :
	public GameObject
{
private:
	Brick *mUpperPipe;
	Brick *mLowerPipe;
public:
	Pipe();
	~Pipe();
	void SetPipe(Vector2D centroid);

	//pure virtual functions
	void Initialize();
	void Update(float deltatime);
	void Render();
	void Destroy();
	bool HandleEvent(Event *_event);
};


#endif