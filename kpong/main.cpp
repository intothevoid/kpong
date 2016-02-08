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

	// Lock our framerate at FPS frames per second
	unsigned int lastTime = 0, currentTime = 0;

	while (running)
	{
		currentTime = engine.getTicks();

		if (currentTime - lastTime > (1000 / FPS))
		{
			engine.pollevent();
			engine.processKeys();
			engine.logic();
			engine.drawscreen();

			lastTime = currentTime;
		}

		running = !engine.quitSDLEventFired(); // check if SDL quit event fired
	}

	engine.quitgame();

	return 0;
}