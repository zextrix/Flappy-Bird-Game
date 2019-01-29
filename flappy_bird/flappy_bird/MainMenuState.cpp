#include "MainMenuState.h"


MainMenuState *MainMenuState::mspMainMenuState = nullptr;


MainMenuState::MainMenuState(){}


MainMenuState::~MainMenuState()
{
	for (Button* button : mCollectionOfButtons)
		button->Destroy();
	mCollectionOfButtons.clear();
	EventManager::GetInstance()->UnregisterListener(mspMainMenuState);
}


MainMenuState* MainMenuState::GetInstance()
{
	if (mspMainMenuState == nullptr)
	{
		mspMainMenuState = new MainMenuState();
		mspMainMenuState->Initialize();
	}

	if (mspMainMenuState == nullptr) std::cout << "Error @MainMenuState -> GetInstance\n";

	return mspMainMenuState;
}


void MainMenuState::Initialize()
{
	std::cout << "in main menu\n";
	Button *create = new Button("create", CreateState::GetInstance(), Vector2D(Window::GetInstance()->GetWidth() / 3, 100), Vector2D(Window::GetInstance()->GetWidth() / 3, 100));
	mCollectionOfButtons.push_back(create);

	Button *join = new Button("join", JoinState::GetInstance(), Vector2D(Window::GetInstance()->GetWidth() / 3, 300), Vector2D(Window::GetInstance()->GetWidth() / 3, 100));
	mCollectionOfButtons.push_back(join);

	Button *exit = new Button("exit", ExitState::GetInstance(), Vector2D(Window::GetInstance()->GetWidth() / 3, 500), Vector2D(Window::GetInstance()->GetWidth() / 3, 100));
	mCollectionOfButtons.push_back(exit);
}


void MainMenuState::Update(float deltaTime){}


void MainMenuState::Render()
{
	for (Button* button : mCollectionOfButtons)
		button->Render();
}


void MainMenuState::Destroy()
{
	delete mspMainMenuState;
	mspMainMenuState = nullptr;
}


void MainMenuState::Activate()
{
	EventManager::GetInstance()->RegisterListener(mspMainMenuState);
}


void MainMenuState::DeActivate()
{
	EventManager::GetInstance()->UnregisterListener(mspMainMenuState);
}


bool MainMenuState::HandleEvent(Event *_event)
{
	if (StateManager::GetInstance()->IsCurrentState(MainMenuState::GetInstance()))
	{
		for (Button* listener : mCollectionOfButtons)
			if (listener->HandleEvent(_event))
			{
				StateManager::GetInstance()->PushState(listener->GoToState());

				for (Button *button : mCollectionOfButtons)
				{
					GameState *game_state = button->GoToState();
					if (!StateManager::GetInstance()->IsCurrentState(game_state))
						game_state->DeActivate();
				}
				return true;
			}
	}

	return false;
}