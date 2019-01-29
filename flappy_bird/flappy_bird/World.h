#pragma once
#ifndef WORLD_H
#define WORLD_H

#include <map>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "Brick.h"

class World :
	public Listener
{
private:
	std::map<std::string, std::vector<GameObject*> > mCollectionOfGameObjects;
	std::vector<Listener*> mListeners;
	Texture mTexture;

public:
	World();
	~World();

	void AddObject(std::string name, GameObject* ptr, bool listener=false);
	std::vector<GameObject*>& GetGameObject(std::string name);
	void ClearGameObjects();

	//call every AddObject here
	bool Initialize();
	void Update(float deltaTime);
	void Render();
	void Destroy();
	bool HandleEvent(Event *_event);
};

#endif