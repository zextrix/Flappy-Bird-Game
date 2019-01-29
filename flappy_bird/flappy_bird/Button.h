#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Events.h"
#include "Listener.h"
#include "Vector2D.h"
#include "Texture.h"
#include "GameState.h"
#include <string>

class Button :
	public Listener
{
private:
	GameState *mpNextState;
	Vector2D mPosition;
	Vector2D mDimension;
	Texture mTexture;

public:
	Button(std::string name, GameState *nextState, Vector2D position, Vector2D dimension);
	~Button();

	GameState* GoToState();

	void Initilize();
	void Update(float deltTime);
	void Render();
	void Destroy();

	//inherited pure virtual function
	bool HandleEvent(Event *_event);
};


#endif