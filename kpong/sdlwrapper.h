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
	void renderRect(int x, int y, int w, int h);
	void clearScreen();
	int processKeys();
	unsigned int getTicks();
	SDLWrapper();
	~SDLWrapper();
};
