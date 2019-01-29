#pragma once
#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H


#include "SDL.h"
#include "Listener.h"
#include "Events.h"
#include "InputManager.h"
#include "CommandManager.h"

#include <vector>
#include <algorithm>
#include <queue>


class EventManager
{
private:
	static EventManager *mspEventManager;
	std::vector < Listener* > mListeners;
	std::queue < Event* > mEventQueue;

private:
	EventManager();
	void NotifyEvents();
	bool EventQueueEmpty();
public:
	~EventManager();
	static EventManager* GetInstance();
	void ManageEvents();
	bool RegisterListener(Listener* listener);
	bool UnregisterListener(Listener* listener);
	void RaiseEvent(Event *_event);
	void Destroy();
	void Empty();
};


#endif