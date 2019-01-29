#pragma once
#ifndef EXIT_STATE_H
#define EXIT_STATE_H


#include "GameState.h"
#include "Managers.h"


class ExitState :
	public GameState
{
private:
	static ExitState *mspExitState;
private:
	ExitState();
	~ExitState();
public:
	static ExitState* GetInstance();

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