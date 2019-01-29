#pragma once
#ifndef PLAYER_H
#define PLAYER_H


#include "GameObject.h"
#include "InputEvent.h"
#include "Managers.h"
#include <string>


class Player :
	public GameObject
{
private:
	std::string mIP;
	bool mIsDead;
	Vector2D mSpeed;

public:
	Player(std::string ip);
	~Player();
	void SetIsDead(bool isDead);
	bool GetIsDead();
	void Load(std::string image);

	//pure virtual functions
	void Initialize();
	void Update(float deltatime);
	void Render();
	void Destroy();
	bool HandleEvent(Event *_event);
};


#endif