#pragma once

#include <vector>
#include "sdlwrapper.h"
#include "gameobject.h"

class PongEngine
{
private:
	SDLWrapper sdlwrap_;
	std::vector<GWO> vecGWO_; // Vector containing game objects
public:
	PongEngine();
	~PongEngine();

	void init();
	void addgwos();
	void logic();
	void drawscreen();
	void quitgame();
	void pollevent();
	bool quitSDLEventFired();
};

