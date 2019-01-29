#pragma once
#ifndef JOIN_STATE_H
#define JOIN_STATE_H

#include "GameState.h"
#include "Player.h"
#include "Managers.h"

class JoinState :
	public GameState
{
private:
	static JoinState *mspJoinState;
	int mPlayerCount;
	bool mJoined;
private:
	JoinState();
	~JoinState();
public:
	static JoinState* GetInstance();

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