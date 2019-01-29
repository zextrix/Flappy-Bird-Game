#include "Engine.h"


Engine::Engine(){}


Engine::~Engine(){}


void Engine::ManageEvents()
{
	if (EventManager::GetInstance() != nullptr)
		EventManager::GetInstance()->ManageEvents();
}


void Engine::Update(float deltaTime)
{
	if (StateManager::GetInstance()->CurrentState())
		StateManager::GetInstance()->CurrentState()->Update(deltaTime);
}


void Engine::Render()
{
	if (Render::GetInstance() != nullptr)
		Render::GetInstance()->Clear();


	if (StateManager::GetInstance()->CurrentState())
		StateManager::GetInstance()->CurrentState()->Render();


	if (Render::GetInstance() != nullptr) 
		Render::GetInstance()->RenderDisplay();
}


bool Engine::Initialize()
{
	if (Window::GetInstance() == nullptr)
		return false;

	if (Render::GetInstance() == nullptr)
		return false;

	if (UDPConnectionManager::GetInstance() == nullptr)	return false;
	else UDPConnectionManager::GetInstance()->ListenToPort(5000);

	if (CommandManager::GetInstance() == nullptr)
		return false;

	if (EventManager::GetInstance() == nullptr)
		return false;

	if (InputManager::GetInstance() == nullptr)
		return false;
	
	if (TextureManager::GetInstance() == nullptr)
		return false;

	if (StateManager::GetInstance() == nullptr)
		return false;
	else
		StateManager::GetInstance()->PushState(MainMenuState::GetInstance());

	std::cout << "Initialization complete\n";
	return true;
}


void Engine::GameLoop()
{
	while (StateManager::GetInstance()->CurrentState() != ExitState::GetInstance())
	{
		ManageEvents();
		Update(0.0);
		Render();
	}
}


void Engine::Destroy()
{
	if (Window::GetInstance() != nullptr)
		Window::GetInstance()->Destroy();

	if (Render::GetInstance() != nullptr)
		Render::GetInstance()->Destroy();

	if (UDPConnectionManager::GetInstance() != nullptr)
		UDPConnectionManager::GetInstance()->Destroy();

	if (CommandManager::GetInstance() != nullptr)
		CommandManager::GetInstance()->Destroy();

	if (InputManager::GetInstance() != nullptr)
		InputManager::GetInstance()->Destroy();

	if (StateManager::GetInstance() != nullptr)
		StateManager::GetInstance()->Destroy();

	if (TextureManager::GetInstance() != nullptr)
		TextureManager::GetInstance()->Destroy();

	if (MainMenuState::GetInstance() != nullptr)
		MainMenuState::GetInstance()->Destroy();

	if (CreateState::GetInstance() != nullptr)
		CreateState::GetInstance()->Destroy();
	
	if (JoinState::GetInstance() != nullptr)
		JoinState::GetInstance()->Destroy();

	if (ExitState::GetInstance() != nullptr)
		ExitState::GetInstance()->Destroy();
	
	if (PlayState::GetInstance() != nullptr)
		PlayState::GetInstance()->Destroy();

	if (Timer::GetInstance())
		Timer::GetInstance()->Destroy();

	if (EventManager::GetInstance() != nullptr)
		EventManager::GetInstance()->Destroy();

}