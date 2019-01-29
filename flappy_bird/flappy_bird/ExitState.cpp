#include "stdafx.h"
#include "ExitState.h"


ExitState *ExitState::mspExitState = nullptr;


ExitState::ExitState(){}


ExitState::~ExitState()
{
	EventManager::GetInstance()->UnregisterListener(mspExitState);
}


ExitState* ExitState::GetInstance()
{
	if (mspExitState == nullptr)
	{
		mspExitState = new ExitState();
		mspExitState->Initialize();
	}

	return mspExitState;
}


void ExitState::Initialize(){}


void ExitState::Update(float deltaTime){}


void ExitState::Render(){}


void ExitState::Destroy()
{
	delete mspExitState;
	mspExitState = nullptr;
}


void ExitState::Activate()
{
	EventManager::GetInstance()->RegisterListener(mspExitState);
}


void ExitState::DeActivate()
{
	EventManager::GetInstance()->UnregisterListener(mspExitState);
}


bool ExitState::HandleEvent(Event *_event)
{
	return false;
}