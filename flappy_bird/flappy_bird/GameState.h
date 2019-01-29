#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H


#include "Listener.h"


class GameState :
	public Listener
{
protected:
	bool mIsActive;
public:
	GameState();
	~GameState();

	virtual void Initialize() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	virtual void Activate() = 0;
	virtual void DeActivate() = 0;

	//virtual void PauseState() = 0;
	//virtual void ResumeState() = 0;

	//pure virtual function inherited from listener
	virtual bool HandleEvent(Event *_event) = 0;
};

#endif