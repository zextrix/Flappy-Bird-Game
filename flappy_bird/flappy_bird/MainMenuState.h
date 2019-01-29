#pragma once
#ifndef MAIN_MENU_H
#define MAIN_MENU_H


#include "GameState.h"
#include "Button.h"
#include "Vector2D.h"
#include "StateManager.h"
#include <vector>


class MainMenuState :
	public GameState
{
	static MainMenuState *mspMainMenuState;
	std::vector<Button*> mCollectionOfButtons;

private:
	MainMenuState();
	~MainMenuState();
public:
	static MainMenuState* GetInstance();

	//inherited pure virtual functions
	void Initialize();
	void Update(float deltaTime);
	void Render();
	void Destroy();
	void Activate();
	void DeActivate();
	//virtual void PauseState();
	//virtual void ResumeState();
	bool HandleEvent(Event *_event);
};


#endif