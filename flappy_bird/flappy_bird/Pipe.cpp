#include "Pipe.h"


Pipe::Pipe(){}


Pipe::~Pipe(){}

void Pipe::SetPipe(Vector2D centroid)
{
	mLowerPipe = new Brick(centroid + Vector2D(0, Window::GetInstance()->GetHeight() / 8));
	mLowerPipe->GetTexture().Load("lowerpipe.png");
	mLowerPipe->Initialize();
	mUpperPipe = new Brick(centroid + Vector2D(0, -Window::GetInstance()->GetHeight() - Window::GetInstance()->GetHeight() / 8));
	mUpperPipe->GetTexture().Load("upperpipe.png");
	mUpperPipe->Initialize();
}


void Pipe::Initialize(){}

void Pipe::Update(float deltaTime)
{
	//upper or lower dosen't matter
	int px = mUpperPipe->GetPosition().GetX(), dx = mUpperPipe->GetDimension().GetX();
	if ( px < -dx)
	{
		int bh = Window::GetInstance()->GetHeight() / 2, bw = Window::GetInstance()->GetWidth() / 10, wh = Window::GetInstance()->GetHeight(), ww = Window::GetInstance()->GetWidth();
		int gap = (ww - bw) / 4;
		Vector2D centroid(5 * gap, wh / 3 + (rand() % wh) / 3);
		mLowerPipe->SetPosition(Vector2D(px,wh / 8)+centroid);
		mUpperPipe->SetPosition(Vector2D(px, - wh - wh / 8) + centroid);
	}
	mLowerPipe->Update(deltaTime);
	mUpperPipe->Update(deltaTime);
}

void Pipe::Render()
{
	mUpperPipe->Render();
	mLowerPipe->Render();
}

void Pipe::Destroy()
{
	mUpperPipe->Destroy();
	mLowerPipe->Destroy();
	delete this;
}

bool Pipe::HandleEvent(Event *_event){ return false; }
