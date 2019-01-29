#pragma once
#ifndef LISTENER_H
#define LISTENER_H

#include "Event.h"

class Listener
{
public:
	Listener();
	~Listener();
	virtual bool HandleEvent(Event *_event) = 0;
	//virtual Event* RaiseEvent();
};

#endif