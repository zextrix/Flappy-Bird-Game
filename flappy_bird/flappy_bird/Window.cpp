#include "Window.h"


Window *Window::mspWindow = NULL;


Window::Window()
{
}


Window::~Window()
{
	SDL_DestroyWindow(mpWindow);
	SDL_Quit();
}


bool Window::Initialize()
{	//window creation
	if (0 <= SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_DisplayMode current;
		SDL_GetCurrentDisplayMode(0, &current);
		mSCREEN_WIDTH = current.w;
		mSCREEN_HEIGHT = current.h;

		this->mpWindow = SDL_CreateWindow("Game",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			this->mSCREEN_WIDTH,
			this->mSCREEN_HEIGHT,
			SDL_WINDOW_SHOWN|SDL_WINDOW_FULLSCREEN);

		if (this->mpWindow == NULL)
		{
			std::cout << "Error @Window -> Initialize -> SDL_CreateWindow : " << SDL_GetError();
			return false;
		}
	}
	else
	{
		std::cout << "Error @Window -> Initilize -> SDL_Init : " << SDL_GetError();
		return false;
	}
	return true;
}


Window* Window::GetInstance()
{
	if (mspWindow == NULL)
	{
		mspWindow = new Window();
		if (!mspWindow->Initialize())
		{
			mspWindow->Destroy();
			return nullptr;
		}
	}

	if (mspWindow == nullptr) std::cout << "Error @Window -> GetInstance : " << SDL_GetError();

	return mspWindow;
}


SDL_Window* Window::GetWindow()
{
	return this->mpWindow;
}


int Window::GetWidth()
{
	return this->mSCREEN_WIDTH;
}


int Window::GetHeight()
{
	return this->mSCREEN_HEIGHT;
}


void Window::Destroy()
{
	delete mspWindow;
	mspWindow = nullptr;
}