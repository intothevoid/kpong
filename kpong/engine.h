#pragma once

#include "sdlwrapper.h"

class PongEngine
{
private:
	SDLWrapper sdlwrap_;
public:
	PongEngine();
	~PongEngine();

	void init();
	void logic();
	void drawscreen();
	void quitgame();
	void pollevent();
	bool quitSDLEventFired();
};

