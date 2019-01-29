#pragma once
#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "GameState.h"
#include "States.h"
#include <vector>


class StateManager
{
private:
	static StateManager *mspStateManager;
	GameState *mpCurrentState;

private:
	StateManager();
	~StateManager();

public:
	static StateManager* GetInstance();

	void PushState(GameState *gameState);
	//void PopState();
	bool IsCurrentState(GameState *gameState);
	GameState* CurrentState();
	void Destroy();
};

#endif