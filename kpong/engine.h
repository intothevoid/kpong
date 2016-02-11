#pragma once

#include <map>
#include "sdlwrapper.h"
#include "gameobject.h"

class PongEngine
{
private:
	SDLWrapper sdlwrap_;
	std::map<gwo_type, GWO> mapGWO_; // Vector containing game objects
public:
	PongEngine();
	~PongEngine();

	void init();
	void addGWOs();
	void logic();
	void drawscreen();
	void quitgame();
	void pollevent();
	bool quitSDLEventFired();
	void drawGWOs();
	void moveball();
	void processKeys();
	unsigned int getTicks();
	void resetBall();
};


