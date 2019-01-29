#include "StateManager.h"


StateManager *StateManager::mspStateManager = nullptr;


StateManager::StateManager(){}


StateManager::~StateManager()
{
	mpCurrentState = nullptr;
}


StateManager* StateManager::GetInstance()
{
	if (mspStateManager == nullptr)
	{
		mspStateManager = new StateManager();
	}

	if (mspStateManager == nullptr) std::cout << "Error @StateManager\n";

	return mspStateManager;
}


void StateManager::PushState(GameState *gameState)
{
	std::cout << "state changed\n";
	if (mpCurrentState != nullptr) mpCurrentState->DeActivate();
	mpCurrentState = gameState;
	if(mpCurrentState != nullptr) mpCurrentState->Activate();
}


bool StateManager::IsCurrentState(GameState *gameState)
{
	if (mpCurrentState == gameState) return true;
	return false;
}


GameState* StateManager::CurrentState()
{
	return mpCurrentState;
}


void StateManager::Destroy()
{
	delete mspStateManager;
	mspStateManager = nullptr;
}