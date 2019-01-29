#include "Timer.h"


Timer *Timer::mspTimer = NULL;


Timer::Timer()
{
	this->mPaused = false;
	this->mStarted = false;
}


Timer::~Timer(){}


Timer* Timer::GetInstance()
{
	if (mspTimer == NULL)
	{
		mspTimer = new Timer();
	}

	return mspTimer;
}


bool Timer::IsStarted()
{
	return this->mStarted;
}


bool Timer::IsPaused()
{
	return this->mPaused;
}


void Timer::StartTimer()
{
	if (!this->IsStarted())
	{
		this->mStartTime = SDL_GetTicks();
		this->mStarted = true;
		this->mPaused = false;
	}
}


void Timer::StopTimer()
{
	this->mStarted = false;
	this->mPaused = false;
}


void Timer::PauseTimer()
{
	if (this->IsStarted())
	{
		if (!this->IsPaused())
		{
			this->mPauseTime = SDL_GetTicks();
			this->mPaused = true;
		}
	}
}


void Timer::UnPauseTimer()
{
	if (this->IsStarted())
	{
		if (this->IsPaused())
		{
			this->mStartTime += (SDL_GetTicks() - this->mPauseTime);
			this->mPaused = false;
		}
	}
}


unsigned int Timer::GetTime()
{
	if (this->IsStarted())
	{

		if (!this->IsPaused())
		{
			return SDL_GetTicks() - this->mStartTime;
		}
		else{

			return this->mPauseTime - this->mStartTime;
		}
	}
	
	return 0;
}


void Timer::Destroy()
{
	delete mspTimer;
	mspTimer = nullptr;
}
