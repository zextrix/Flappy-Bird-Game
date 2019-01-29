#include "InputManager.h"


InputManager *InputManager::mspInputManager = nullptr;


InputManager::InputManager(){}


InputManager::~InputManager(){}


InputManager* InputManager::GetInstance()
{
	if (mspInputManager == nullptr)
	{
		mspInputManager = new InputManager();
	}

	if (mspInputManager == nullptr) std::cout << "Error @InputManager\n";

	return mspInputManager;
}


void InputManager::Load()
{
	SDL_Event sdl_event;
	while (SDL_PollEvent(&sdl_event) != 0)
	{
		EventManager::GetInstance()->RaiseEvent(new InputEvent(sdl_event));
	}
}


void InputManager::Destroy()
{
	delete mspInputManager;
	mspInputManager = nullptr;
}