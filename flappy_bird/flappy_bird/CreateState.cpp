#include "CreateState.h"


CreateState *CreateState::mpCreateState = nullptr;


CreateState::CreateState()
{
}


CreateState::~CreateState()
{
	for (Button* button : mCollectionOfButtons)
		button->Destroy();
	mCollectionOfButtons.clear();
	EventManager::GetInstance()->UnregisterListener(mpCreateState);
}


CreateState* CreateState::GetInstance()
{
	if (mpCreateState == nullptr)
	{
		mpCreateState = new CreateState();
		mpCreateState->Initialize();
	}
	return mpCreateState;
}


void CreateState::Initialize()
{
	Button *start = new Button("start", PlayState::GetInstance(), Vector2D(Window::GetInstance()->GetWidth() / 3, 100), Vector2D(Window::GetInstance()->GetWidth() / 3, 100));
	mCollectionOfButtons.push_back(start);
	//mBroadcastMessage.SetOpcode(CommandEvent::BROADCAST);
}


void CreateState::Update(float deltaTime)
{
	//CommandManager::GetInstance()->Broadcast(mBroadcastMessage.ToString());
}


void CreateState::Render()
{
	//std::cout << mCollectionOfButtons.size() << " in create\n" ;
	for (Button* button : mCollectionOfButtons)
		button->Render();
}


void CreateState::Destroy()
{
	delete mpCreateState;
	mpCreateState = nullptr;
}


void CreateState::Activate()
{
	if (!mIsActive)
	{
		mIsActive = false;
	}

	EventManager::GetInstance()->RegisterListener(mpCreateState);
	mPlayersData.push_back(UDPConnectionManager::GetInstance()->GetMyIP());
}


void CreateState::DeActivate()
{
	EventManager::GetInstance()->UnregisterListener(mpCreateState);
	CommandManager::GetInstance()->SetIsServer(true);
	mPlayersData.clear();
}


bool CreateState::HandleEvent(Event *_event)
{
	if (StateManager::GetInstance()->IsCurrentState(CreateState::GetInstance()))
	{
		CommandEvent *pcommand_event = dynamic_cast<CommandEvent*>(_event);
		if (pcommand_event != nullptr && pcommand_event->GetOpcode() == CommandEvent::REQUEST)
		{
			//std::cout << "in in\n";
			// add players
			if (find(mPlayersData.begin(), mPlayersData.end(), pcommand_event->GetData()) == mPlayersData.end())
			{
				//std::cout << "in in in\n";
				mPlayersData.push_back(pcommand_event->GetData());
				UDPConnectionManager::GetInstance()->SetRemoteIPAndPort(pcommand_event->GetData(), 5000);
			}
			return true;
		}

		for (Button* listener : mCollectionOfButtons)
			if (listener->HandleEvent(_event))
			{
				World *pworld = PlayState::GetInstance()->GetWorld();
				int xp = 200, yp = 100, player_count = 0;
				std::cout << "creatstate : " << mPlayersData.size() << std::endl;
				for (auto player : mPlayersData)
				{
					Player *pplayer = new Player(player);
					pplayer->SetPosition(Vector2D(xp,yp));
					pplayer->Load("bird"+std::to_string(++player_count)+".png");
					pworld->AddObject("player", pplayer, true);
					
					//send it to others
					CommandEvent command_event;
					command_event.SetOpcode(CommandEvent::ADD_PLAYER);
					command_event.SetData(player);
					command_event.SetPosition(pplayer->GetPosition());
					command_event.SetIsDead(false);
					CommandManager::GetInstance()->UnLoad(command_event.ToString());

					xp += 50;
					yp += 110;
					
				}
				
				int seed = time(NULL);
				srand(seed);

				CommandEvent command_event;
				command_event.SetOpcode(CommandEvent::SEED);
				command_event.SetData(std::to_string(seed));
				CommandManager::GetInstance()->UnLoad(command_event.ToString());

				
				command_event.SetOpcode(CommandEvent::START);
				CommandManager::GetInstance()->UnLoad(command_event.ToString());

				StateManager::GetInstance()->PushState(listener->GoToState());
				return true;
			}
	}
	return false;
}