#include "CommandManager.h"


CommandManager *CommandManager::mspCommandManager = nullptr;


CommandManager::CommandManager()
{
	mIsServer = false;
}


CommandManager::~CommandManager(){}


CommandManager* CommandManager::GetInstance()
{
	if (mspCommandManager == nullptr)
	{
		mspCommandManager = new CommandManager();
	}

	if (mspCommandManager == nullptr) std::cout << "Error @CommandManager\n";

	return mspCommandManager;
}


void CommandManager::Load()
{
	for (std::string command = UDPConnectionManager::GetInstance()->ReceiveEvent();
		command != "";
		command = UDPConnectionManager::GetInstance()->ReceiveEvent())
	{
		EventManager::GetInstance()->RaiseEvent(new CommandEvent(command));
		if (GetIsServer())
			this->UnLoad(command);
		//std::cout << "load : " << command << std::endl;
	}
}


void CommandManager::UnLoad(std::string out)
{
	std::cout << "unload : " << out << std::endl;
	UDPConnectionManager::GetInstance()->SendEvent(out);
}


void CommandManager::SetIsServer(bool isServer)
{
	mIsServer = isServer;
}


bool CommandManager::GetIsServer()
{
	return false;
}


void CommandManager::Broadcast(std::string out)
{
	//UDPConnectionManager::GetInstance()->Broadcast(out);
}


void CommandManager::Destroy()
{
	delete mspCommandManager;
}