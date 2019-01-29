#pragma once
#ifndef CREATE_STATE_H
#define CREATE_STATE_H


#include "GameState.h"
#include "Button.h"
#include "StateManager.h"
#include "Player.h"
#include <vector>


class CreateState :
	public GameState
{
private:
	static CreateState *mpCreateState;
	std::vector<Button*> mCollectionOfButtons;
	std::vector<std::string> mPlayersData;
	//CommandEvent mBroadcastMessage;
private:
	CreateState();
	~CreateState();
public:
	static CreateState* GetInstance();

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