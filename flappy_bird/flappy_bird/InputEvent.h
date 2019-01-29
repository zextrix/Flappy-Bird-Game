#pragma once
#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "Event.h"
#include "SDL.h"
#include "Vector2D.h"
#include <string>

class InputEvent :
	public Event
{
	SDL_Event mInputEvent;
public:
	InputEvent(SDL_Event _event);
	~InputEvent();
	
	bool IsKeyPressed();
	bool IsKeyReleased();
	bool IsMouseButtonPressed();
	bool IsMouseButtonReleased();
	bool IsMouseLeftButtonPressed();
	bool IsMouseLeftButtonReleased();
	bool IsMouseRightButtonPressed();
	bool IsMouseRightButtonReleased();
	Vector2D GetMouseClickedPosition();
	std::string GetKey();
};

#endif