#pragma once
#include "sdlwrapper.h"
#include "engine.h"

int main(int argc, char* argv[])
{
	PongEngine engine;
	bool running = true;

	// Init SDL and create our
	engine.init();

	// Add game world objects
	engine.addGWOs();

	while (running)
	{
		engine.pollevent();

		running = !engine.quitSDLEventFired(); // check if SDL quit event fired

		engine.logic();
		engine.drawscreen();
	}

	engine.quitgame();

	return 0;
}