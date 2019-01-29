#include "PlayState.h"


PlayState *PlayState::mspPlayState = nullptr;


PlayState::PlayState(){}


PlayState::~PlayState()
{
	if(mpWorld != nullptr) mpWorld->Destroy();
	mpWorld = nullptr;
	EventManager::GetInstance()->UnregisterListener(mspPlayState);
}


PlayState* PlayState::GetInstance()
{
	if (mspPlayState == nullptr)
	{
		mspPlayState = new PlayState();
		mspPlayState->Initialize();
	}

	return mspPlayState;
}


World* PlayState::GetWorld()
{
	//if (mpWorld == nullptr) mpWorld = new World(), mpWorld->Initialize();
	return mpWorld;
}


void PlayState::SetGameOver(bool state)
{
	mGameOver = state;
}


void PlayState::Initialize()
{
	mGameOver = false;
	mpWorld = new World();
	mpWorld->Initialize();
}


void PlayState::Update(float deltaTime)
{
	if (!mIsActive)
	{
		Timer::GetInstance()->StartTimer();
		mIsActive = true;
	}

	if (mGameOver)
	{
		if (CommandManager::GetInstance()->GetIsServer() == true)
		{
			mPlayerCount--;
		}
		else mPlayerCount = 0;
		//SDL_Delay(2000);
		
		if (mPlayerCount == 0)
		{
			StateManager::GetInstance()->PushState(MainMenuState::GetInstance());
			mIsActive = false;
			mGameOver = false;
			return;
		}
	}

	uint32_t delta_time = 0;
	while (delta_time < 33)
	{
		mCurrentFrameTime = Timer::GetInstance()->GetTime();
		delta_time = mCurrentFrameTime - mPreviousFrameTime;
	}
	std::cout << "\rFPS : " << (1000.0 / delta_time) ;
	mPreviousFrameTime = mCurrentFrameTime;
	mpWorld->Update(delta_time/1000.0);
}


void PlayState::Render()
{
	mpWorld->Render();
}


void PlayState::Destroy()
{
	delete mspPlayState;
	mspPlayState = nullptr;
}


void PlayState::Activate()
{
	//std::cout << "in playstate\n\n";
	EventManager::GetInstance()->RegisterListener(mspPlayState);

	int bh = Window::GetInstance()->GetHeight() / 2, bw = Window::GetInstance()->GetWidth() / 10, wh = Window::GetInstance()->GetHeight(), ww = Window::GetInstance()->GetWidth();
	int gap = (ww - bw) / 4;
	int wh3 = wh / 3;
	for (int i = 0; i < 5; i++)
	{
		Vector2D centroid(ww/2 + gap*i, wh/3 + (rand()%wh)/3);
		Pipe *pipe = new Pipe();
		pipe->SetPipe(centroid);
		mpWorld->AddObject("pipe", pipe);
	}

	mPlayerCount = mpWorld->GetGameObject("player").size();
}


void PlayState::DeActivate()
{
	EventManager::GetInstance()->RegisterListener(mspPlayState);
	mpWorld->ClearGameObjects();
	CommandManager::GetInstance()->SetIsServer(false);
	EventManager::GetInstance()->Empty();
	UDPConnectionManager::GetInstance()->UnBindChannel();
}


bool PlayState::HandleEvent(Event *_event)
{
	if (StateManager::GetInstance()->IsCurrentState(mspPlayState))
		return mpWorld->HandleEvent(_event);
	return false;
}