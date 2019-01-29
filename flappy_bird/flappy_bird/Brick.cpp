#include "stdafx.h"
#include "Brick.h"


Brick::Brick(Vector2D position)
{
	SetPosition(position);
	SetDimension(Vector2D(Vector2D(Window::GetInstance()->GetWidth() / 10, Window::GetInstance()->GetHeight())));
}


Brick::~Brick(){}


void Brick::IsCollision()
{
	std::vector<GameObject*> player = PlayState::GetInstance()->GetWorld()->GetGameObject("player");
	for (GameObject* game_object : player)
	{
		Vector2D p1 = game_object->GetPosition(), p2 = game_object->GetPosition() + game_object->GetDimension();
		
		if ((GetPosition() <= p1 && p1 <= (GetPosition() + GetDimension())) || (GetPosition() <= p2 && p2 <= (GetPosition() + GetDimension())))
		{
			Player* _player = dynamic_cast<Player*>(game_object);
			if (_player != nullptr)
			{
				_player->SetIsDead(true);
				std::cout << "\nDEAD !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
				//PlayState::GetInstance()->SetGameOver(true);
				break;
			}
		}
	}
}

void Brick::Initialize()
{
	mSpeed = Vector2D(-150, 0);
}


void Brick::Update(float deltaTime)
{
	SetPosition(GetPosition() + mSpeed*deltaTime);
	IsCollision();
}


void Brick::Render()
{
	GetTexture().Render(GetPosition(), GetDimension());
}

void Brick::Destroy()
{
	delete this;
}


bool Brick::HandleEvent(Event *_event)
{
	return false;
}