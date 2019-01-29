#include "JoinState.h"
#include <iostream>

JoinState *JoinState::mspJoinState = nullptr;


JoinState::JoinState()
{
	mPlayerCount = 0;
}


JoinState::~JoinState()
{
	EventManager::GetInstance()->UnregisterListener(mspJoinState);
}


JoinState* JoinState::GetInstance()
{
	if (mspJoinState == nullptr)
	{
		mspJoinState = new JoinState();
		mspJoinState->Initialize();
	}

	return mspJoinState;
}


void JoinState::Initialize()
{
	mJoined = false;
}

 
void JoinState::Update(float deltaTime){}


void JoinState::Render(){}


void JoinState::Destroy()
{
	delete mspJoinState;
	mspJoinState = nullptr;
}


void JoinState::Activate()
{
	mPlayerCount = 0;
	CommandManager::GetInstance()->SetIsServer(false);
	UDPConnectionManager::GetInstance()->SetRemoteIPAndPort("10.206.24.58", 5000);
	EventManager::GetInstance()->RegisterListener(mspJoinState);
	CommandEvent command_event;
	command_event.SetOpcode(CommandEvent::REQUEST);
	command_event.SetData(UDPConnectionManager::GetInstance()->GetMyIP());
	CommandManager::GetInstance()->UnLoad(command_event.ToString());
	mJoined = false;
}


void JoinState::DeActivate()
{
	EventManager::GetInstance()->UnregisterListener(mspJoinState);
}


bool JoinState::HandleEvent(Event *_event)
{
	if (StateManager::GetInstance()->IsCurrentState(mspJoinState))
	{
		CommandEvent *pcommand_event = dynamic_cast<CommandEvent*>(_event);
		if (pcommand_event != nullptr)
		{
			std::string ip = pcommand_event->GetData();
	

			if (pcommand_event->GetOpcode() == CommandEvent::ADD_PLAYER)
			{
				World *pworld = PlayState::GetInstance()->GetWorld();
				Player *pplayer = new Player(ip);
				pplayer->SetPosition(pcommand_event->GetPosition());
				pplayer->Load("bird" + std::to_string(++mPlayerCount) + ".png");
				pworld->AddObject("player", pplayer, true);
				return true;
			}
			else if (pcommand_event->GetOpcode() == CommandEvent::SEED)
			{
				srand(std::stoi(pcommand_event->GetData()));
				return true;
			}
			else if (pcommand_event->GetOpcode() == CommandEvent::START)
			{
				StateManager::GetInstance()->PushState(PlayState::GetInstance());
				return true;
			}
		}
	}
	return false;
}