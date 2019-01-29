#pragma once
#ifndef ENGINE_H
#define ENGINE_H


#include "Managers.h"
#include <vector>


class Engine
{
private:
	void ManageEvents();
	void Update(float deltaTime);
	void Render();	
	
	void LoadCurrentState();
public:
	Engine();
	~Engine();

	bool Initialize();
	void GameLoop();
	void Destroy();
};

#endif