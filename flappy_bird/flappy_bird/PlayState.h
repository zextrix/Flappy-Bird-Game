#pragma once
#ifndef PLAY_STATE_H
#define PLAY_STATE_H


#include "GameState.h"
#include "Managers.h"
#include "World.h"
#include "Timer.h"
#include "GameObjects.h"

class World;

class PlayState :
	public GameState
{
private:
	static PlayState *mspPlayState;	
	World *mpWorld;
	uint32_t mCurrentFrameTime, mPreviousFrameTime;
	bool mGameOver;
	int32_t mPlayerCount;

private:
	PlayState();
	~PlayState();
public:
	static PlayState* GetInstance();
	World* GetWorld();
	void SetGameOver(bool state);

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