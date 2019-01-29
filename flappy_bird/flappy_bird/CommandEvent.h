#pragma once
#ifndef COMMAND_EVENT_H
#define COMMAND_EVENT_H


#include "Event.h"
#include "SDL_net.h"
#include "Vector2D.h"
#include <string>
#include <sstream>
#include <map>


class CommandEvent :
	public Event
{
private:
	int mOpcode;
	std::string mData;
	Vector2D mPosition;
	bool mIsDead;
	static std::map<std::string, int> mCommands;
public:
	enum { BROADCAST, REQUEST, ADD_PLAYER, SEED, START, BIRD_SPEED };

public:
	CommandEvent();
	CommandEvent(std::string command);
	~CommandEvent();

	void SetOpcode(int opcode);
	void SetData(std::string data);
	void SetPosition(Vector2D position);
	void SetIsDead(bool isDead);

	int GetOpcode();
	std::string GetData();
	Vector2D GetPosition();
	bool GetIsDead();

	std::string ToString();
};

#endif