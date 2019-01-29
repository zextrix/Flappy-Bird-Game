#pragma once
#ifndef TIMER_H
#define TIMER_H


#include "SDL.h"


class Timer
{
private:
	static Timer* mspTimer;
	unsigned int mStartTime;
	unsigned int mPauseTime;
	bool mPaused;
	bool mStarted;

private:
	Timer();
	~Timer();
public:
	static Timer* GetInstance();

	bool IsStarted();
	bool IsPaused();
	
	void StartTimer();
	void StopTimer();
	
	void PauseTimer();
	void UnPauseTimer();

	unsigned int GetTime();
	
	void Destroy();
};


#endif