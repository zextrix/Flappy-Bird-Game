#include "stdafx.h"
#include "InputEvent.h"


InputEvent::InputEvent(SDL_Event _event)
{
	mInputEvent = _event;
}


InputEvent::~InputEvent(){}


bool InputEvent::IsKeyPressed()
{
	return (mInputEvent.type == SDL_KEYDOWN);
}


bool InputEvent::IsKeyReleased()
{
	return (mInputEvent.type == SDL_KEYUP);
}


bool InputEvent::IsMouseButtonPressed()
{
	return (mInputEvent.type == SDL_MOUSEBUTTONDOWN);
}


bool InputEvent::IsMouseButtonReleased()
{
	return (mInputEvent.type == SDL_MOUSEBUTTONUP);
}


bool InputEvent::IsMouseLeftButtonPressed()
{
	if (IsMouseButtonPressed())
		return (mInputEvent.button.button == SDL_BUTTON_LEFT);
}


bool InputEvent::IsMouseLeftButtonReleased()
{
	if (IsMouseButtonReleased())
		return (mInputEvent.button.button == SDL_BUTTON_LEFT);
}


bool InputEvent::IsMouseRightButtonPressed()
{
	if (IsMouseButtonPressed())
		return (mInputEvent.button.button == SDL_BUTTON_RIGHT);
}


bool InputEvent::IsMouseRightButtonReleased()
{
	if (IsMouseButtonReleased())
		return (mInputEvent.button.button == SDL_BUTTON_RIGHT);
}


std::string InputEvent::GetKey()
{
	return std::string(SDL_GetKeyName(mInputEvent.key.keysym.sym));
}


Vector2D InputEvent::GetMouseClickedPosition()
{
	return Vector2D(mInputEvent.button.x, mInputEvent.button.y);
}