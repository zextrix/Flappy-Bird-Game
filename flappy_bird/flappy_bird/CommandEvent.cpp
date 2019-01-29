#include "CommandEvent.h"


std::map<std::string, int> CommandEvent::mCommands = {	{ "NULL", -1 },
														{ "BDCT", CommandEvent::BROADCAST },
														{ "REQT", CommandEvent::REQUEST },
														{ "ADDP", CommandEvent::ADD_PLAYER },
														{ "SEED", CommandEvent::SEED },
														{ "STRT", CommandEvent::START },
														{ "YSPD", CommandEvent::BIRD_SPEED } };


CommandEvent::CommandEvent()
{
	mOpcode = -1;
	mData = "NULL";
	mPosition = Vector2D();
	mIsDead = false;
}


CommandEvent::CommandEvent(std::string command)
{
	std::string opcode;
	std::stringstream sin(command);
	sin >> opcode;//compulsory
	mOpcode = mCommands[opcode];
	sin >> mData;
	float x, y;
	sin >> x;
	mPosition.SetX(x);
	sin >> y;
	mPosition.SetY(y);
	sin >> mIsDead;
}


CommandEvent::~CommandEvent(){}


void CommandEvent::SetOpcode(int opcode)
{
	mOpcode = opcode;
}


void CommandEvent::SetData(std::string data)
{
	mData = data;
}


void CommandEvent::SetPosition(Vector2D position)
{
	mPosition = position;
}


void CommandEvent::SetIsDead(bool isDead)
{
	mIsDead = isDead;
}


int CommandEvent::GetOpcode()
{
	return mOpcode;
}


std::string CommandEvent::GetData()
{
	return mData;
}


Vector2D CommandEvent::GetPosition()
{
	return mPosition;
}


bool CommandEvent::GetIsDead()
{
	return mIsDead;
}


std::string CommandEvent::ToString()
{
	std::string opcode;
	for (auto it : mCommands)
		if (it.second == mOpcode)
		{
			opcode = it.first;
			break;
		}

	return opcode + "\n" + mData + "\n" + std::to_string(mPosition.GetX()) + " " + std::to_string(mPosition.GetY()) + "\n" + std::to_string(mIsDead);
}