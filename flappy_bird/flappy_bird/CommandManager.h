#pragma once
#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H


#include "EventManager.h"
#include "UDPConnectionManager.h"


class CommandManager
{
private:
	static CommandManager *mspCommandManager;
	bool mIsServer;

private:
	CommandManager();
	~CommandManager();
public:
	static CommandManager* GetInstance();
	void Load();
	void UnLoad(std::string out);
	void Destroy();

	//ignore server related things, they are not used
	void SetIsServer(bool isServer);
	bool GetIsServer();
	void Broadcast(std::string out);
};


#endif