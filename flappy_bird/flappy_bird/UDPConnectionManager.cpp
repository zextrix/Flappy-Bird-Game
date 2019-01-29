#include "UDPConnectionManager.h"


UDPConnectionManager *UDPConnectionManager::mspUDPConnectionManager = nullptr;


UDPConnectionManager::UDPConnectionManager()
{
	mMyIp = "";
}


UDPConnectionManager::~UDPConnectionManager()
{	
	SDLNet_UDP_Unbind(mLocalSocket, mChannel);
	SDLNet_FreePacket(mPacket);
	SDLNet_UDP_Close(mLocalSocket);
	SDLNet_Quit();
}


void UDPConnectionManager::Destroy()
{
	delete mspUDPConnectionManager;
	mspUDPConnectionManager = nullptr;
}


bool UDPConnectionManager::Initialize()
{
	if (SDLNet_Init() == -1)
	{
		std::cout << "Error @UDPConnectionManager -> Initialize -> SDLNet_Init : " << SDLNet_GetError() << std::endl;
		return false;
	}
	
	mChannel = -1;
	
	if ((mPacket = SDLNet_AllocPacket(512)) == nullptr)
	{
		std::cout << "Error @UDPConnectionManager -> Initialize -> SDLNet_AllocPacket : " << SDLNet_GetError() << std::endl;
		return false;
	}

	return true;
}


UDPConnectionManager* UDPConnectionManager::GetInstance()
{
	if (mspUDPConnectionManager == nullptr)
	{
		mspUDPConnectionManager = new UDPConnectionManager();
		if (!mspUDPConnectionManager->Initialize())
		{
			mspUDPConnectionManager->Destroy();
			return nullptr;
		}
	}

	if (mspUDPConnectionManager == nullptr) std::cout << "Error @UDPConnectionManager -> GetInstance\n";
	
	return mspUDPConnectionManager;
}


bool UDPConnectionManager::ListenToPort(int32_t port)
{
	mLocalSocket = SDLNet_UDP_Open(port);
	if (!mLocalSocket) 
	{
		std::cout << "Error @UDPConnectionManager -> ListenToPort -> SDLNet_UDP_Open : " << SDLNet_GetError();
		return false;
	}
	return true;
}


bool UDPConnectionManager::SetRemoteIPAndPort(std::string ip, int32_t port)
{
	IPaddress address;
	if (SDLNet_ResolveHost(&address, ip.c_str(), port) == -1)
	{
		std::cout << "Error @UDPConnectionManager -> SetRemoteIPAndPort -> SDLNet_ResolveHost : " << SDLNet_GetError() << std::endl;
		return false;
	}

	mChannel = SDLNet_UDP_Bind(mLocalSocket, mChannel, &address);
	if (mChannel < 0)
	{
		std::cout << "Error @UDPConnectionManager -> SetRemoteIPAndPort -> SDLNet_UDP_Bind : " << SDLNet_GetError() << std::endl;
		return false;
	}

	return true;
}


void UDPConnectionManager::UnBindChannel()
{
	SDLNet_UDP_Unbind(mLocalSocket, mChannel);
}


bool UDPConnectionManager::SendEvent(std::string command)
{
	memcpy(mPacket->data, command.c_str(), command.length());
	mPacket->len = command.length();
	if (SDLNet_UDP_Send(mLocalSocket, mChannel, mPacket) == 0)
	{
		std::cout << "Error @UDPConnectionManager -> SendEvent -> SDLNet_UDP_Send" << SDLNet_GetError();
		return false;
	}
	return true;
}


std::string UDPConnectionManager::ReceiveEvent()
{
	if (SDLNet_UDP_Recv(mLocalSocket, mPacket)) return std::string((char*)mPacket->data);
	return "";
}


void UDPConnectionManager::Broadcast(std::string command)
{
	//mPacket->address.host = INADDR_BROADCAST;
	//mPacket->address.port = 5000;
	mPacket->len = command.length();
	memcpy(mPacket->data, command.c_str(), command.length());
	//std::cout << "broadcast : " << SDLNet_UDP_Send(mLocalSocket, -1, mPacket) <<std::endl;
}


std::string UDPConnectionManager::GetMyIP()
{
	if (mMyIp == "")
	{
		system("%cd%\\ipconfig.exe");
		std::ifstream fin("ipconfig.txt");
		std::string line = "";
		fin >> line;
		mMyIp = line;
	}
	return mMyIp;
}

