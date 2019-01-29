#pragma once
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H


#include "SDL.h"
#include "EventManager.h"


class InputManager
{
private:
	static InputManager *mspInputManager;

private:
	InputManager();
	~InputManager();
public:
	static InputManager* GetInstance();
	void Load();
	void Destroy();
};

#endif