#pragma once
#ifndef UDP_CONNECTION_MANAGER_H
#define UDP_CONNECTION_MANAGER_H


#include "SDL_net.h"
#include "Event.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iomanip>


class UDPConnectionManager
{
private:
	static UDPConnectionManager *mspUDPConnectionManager;
	UDPsocket mLocalSocket;
	UDPpacket *mPacket;
	int mChannel;
	std::string mMyIp;

private:
	UDPConnectionManager();
	~UDPConnectionManager();
	bool Initialize();
public:
	static UDPConnectionManager* GetInstance();
	bool ListenToPort(int32_t port);
	bool SetRemoteIPAndPort(std::string ip, int32_t port);
	void UnBindChannel();
	bool IsQueueEmpty();
	bool SendEvent(std::string data);
	std::string GetMyIP();
	std::string ReceiveEvent();
	void Broadcast(std::string command);
	void Destroy();
};

#endif