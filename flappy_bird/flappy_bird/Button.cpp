#include "Button.h"


Button::Button(std::string name,GameState *nextState, Vector2D position, Vector2D dimension)
{
	mpNextState = nextState;
	this->mTexture.Load(name+".png");
	this->mPosition = position;
	this->mDimension = dimension;
}


Button::~Button(){}


GameState* Button::GoToState()
{
	return mpNextState;
}


void Button::Initilize(){}


void Button::Update(float deltTime){}


void Button::Render()
{
	this->mTexture.Render(mPosition, mDimension);
}


void Button::Destroy()
{
	delete this;
}


bool Button::HandleEvent(Event *_event)
{
	InputEvent* input_event = dynamic_cast<InputEvent*>(_event);
	if (input_event != nullptr)
	{
		if (input_event->IsMouseButtonPressed())
		{
			Vector2D position = input_event->GetMouseClickedPosition();
			if ((mPosition <= position) && (position <= (mPosition + mDimension))) return true;
		}
	}
	return false;
}