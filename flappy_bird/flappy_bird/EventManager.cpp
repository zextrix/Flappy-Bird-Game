#include "stdafx.h"
#include "EventManager.h"


EventManager *EventManager::mspEventManager = nullptr;


EventManager::EventManager(){}


EventManager::~EventManager()
{
	mspEventManager->mListeners.clear();
	while (!mEventQueue.empty())
	{
		delete mEventQueue.front();
		mEventQueue.pop();
	}
}


EventManager* EventManager::GetInstance()
{
	if (mspEventManager == NULL)
	{
		mspEventManager = new EventManager();
		std::cout << "Error @EventManager Initialized\n";
	}

	if (mspEventManager == nullptr) std::cout << "Error @EventManager\n";

	return mspEventManager;
}


bool EventManager::RegisterListener(Listener* listener)
{
	if (std::find(this->mListeners.begin(), this->mListeners.end(), listener) == this->mListeners.end())//not registered already
	{
		this->mListeners.push_back(listener);
		return true;
	}
	return false;
}


bool EventManager::UnregisterListener(Listener* listener)
{
	if (listener != NULL)
	{
		std::vector<Listener*>::iterator it = std::find(this->mListeners.begin(), this->mListeners.end(), listener);
		if (it != this->mListeners.end())//only if the listener is registered
		{
			mListeners.erase(it);
			return true;
		}
	}
	return false;
}


void EventManager::NotifyEvents()
{
	Event *_event = this->mEventQueue.front();
	for (auto listener : this->mListeners)
		if (listener!=nullptr && listener->HandleEvent(_event)) break;
	delete _event;
	this->mEventQueue.pop();
}


bool EventManager::EventQueueEmpty()
{
	if (this->mEventQueue.empty()) return true;
	return false;
}


void EventManager::ManageEvents()
{
	//poll shit
	InputManager::GetInstance()->Load();
	CommandManager::GetInstance()->Load();
	
	if (!this->EventQueueEmpty()) this->NotifyEvents();
}


void EventManager::RaiseEvent(Event *_event)
{
	mEventQueue.push(_event);
}


void EventManager::Destroy()
{
	delete mspEventManager;
	mspEventManager = nullptr;
}


void EventManager::Empty()
{
	InputManager::GetInstance()->Load();
	CommandManager::GetInstance()->Load();
	while (!mEventQueue.empty())
	{
		delete mEventQueue.front();
		mEventQueue.pop();
	}
}