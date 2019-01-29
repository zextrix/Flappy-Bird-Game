#include "stdafx.h"
#include "Player.h"


Player::Player(std::string ip)
{
	mIP = ip;
	this->SetDimension(Vector2D(Window::GetInstance()->GetWidth()/20, Window::GetInstance()->GetHeight()/15));
	mIsDead = false;
	GetTexture().SetFrameCount(4);
	mSpeed = Vector2D();
}


Player::~Player(){}


void Player::SetIsDead(bool isDead)
{
	mIsDead = isDead;
}


bool Player::GetIsDead()
{
	return mIsDead;
}


void Player::Load(std::string image)
{
	GetTexture().Load(image);
}


void Player::Initialize(){}


void Player::Update(float deltaTime)
{
	if(mIsDead) PlayState::GetInstance()->SetGameOver(true);
	SetPosition(GetPosition() + mSpeed*deltaTime);
	if (Vector2D(-10000, Window::GetInstance()->GetHeight()) < GetPosition() || GetPosition() < Vector2D(10000, 0))
	{
		mIsDead = true;
		PlayState::GetInstance()->SetGameOver(true);
	}
	
	
	mSpeed = mSpeed + Vector2D(0,Window::GetInstance()->GetHeight()/1.6)*deltaTime;
	GetTexture().Update(deltaTime);
}


void Player::Render()
{
	if (!GetIsDead())
		GetTexture().Render(GetPosition(), GetDimension());
}


void Player::Destroy()
{
	delete this;
}


bool Player::HandleEvent(Event *_event)
{
	InputEvent* pinput_event = dynamic_cast<InputEvent*>(_event);
	if (pinput_event != nullptr)
	{
		if (pinput_event->IsMouseLeftButtonPressed() && mIP == UDPConnectionManager::GetInstance()->GetMyIP())
		{
			mSpeed = Vector2D(0,-Window::GetInstance()->GetHeight()/2.5);
			CommandEvent command_event;
			command_event.SetOpcode(CommandEvent::BIRD_SPEED);
			command_event.SetData(mIP);
			CommandManager::GetInstance()->UnLoad(command_event.ToString());
			return true;
		}
	}

	CommandEvent *pcommand_event = dynamic_cast<CommandEvent*>(_event);
	if (pcommand_event != nullptr)
	{
		if (mIP != UDPConnectionManager::GetInstance()->GetMyIP())
			if (pcommand_event->GetOpcode() == CommandEvent::BIRD_SPEED && pcommand_event->GetData() == mIP)
			{
				mSpeed = Vector2D(0, -Window::GetInstance()->GetHeight() / 2.5);
				return true;
			}
	}

	return false;
}