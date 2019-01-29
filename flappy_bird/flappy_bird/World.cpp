#include "World.h"


//std::map<std::string, std::vector<GameObject*> >World::mCollectionOfGameObjects;


World::World(){}


World::~World()
{
	this->ClearGameObjects();
}


void World::AddObject(std::string name, GameObject* ptr, bool listener)
{
	ptr->Initialize();
	mCollectionOfGameObjects[name].push_back(ptr);
	if (listener) mListeners.push_back(ptr);
}


std::vector<GameObject*>& World::GetGameObject(std::string name)
{
	if (mCollectionOfGameObjects[name].size() != 0)
		return mCollectionOfGameObjects[name];
	return std::vector < GameObject* > {NULL};
}


//call every AddObject here
bool World::Initialize()
{
	mTexture.Load("bg.png");
	return true;
}


void World::Update(float deltaTime)
{
	for (auto go : this->mCollectionOfGameObjects)
		for (auto vit : go.second)
			vit->Update(deltaTime);
}


void World::Render()
{
	mTexture.Render(Vector2D(0,0), Vector2D(Window::GetInstance()->GetWidth(), Window::GetInstance()->GetHeight()));
	for (auto go : this->mCollectionOfGameObjects)
		for (auto vit : go.second)
			vit->Render();
}


void World::Destroy()
{
	delete this;
}


bool World::HandleEvent(Event *_event)
{
	for (Listener* listener : mListeners)
		if (listener->HandleEvent(_event)) return true;
	return false;
}


void World::ClearGameObjects()
{
	for (auto obj : mCollectionOfGameObjects)
		for (GameObject *game_object : obj.second)
			game_object->Destroy();
	mListeners.clear();
	mCollectionOfGameObjects.clear();
}