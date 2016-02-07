#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class SDLWrapper
{
public:
	void initSDL();
	void quitSDL();
	void pollevent();
	void createwindow();
	bool quitEventCheck();
	SDLWrapper();
	~SDLWrapper();
};
