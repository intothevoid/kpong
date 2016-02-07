#include "engine.h"

PongEngine::PongEngine()
{
}

PongEngine::~PongEngine()
{
}

void PongEngine::init()
{
	sdlwrap_.initSDL();
	sdlwrap_.createwindow();
}

void PongEngine::quitgame()
{
	sdlwrap_.quitSDL();
}

void PongEngine::logic()
{
}

void PongEngine::drawscreen()
{
}

void PongEngine::pollevent()
{
	sdlwrap_.pollevent();
}

bool PongEngine::quitSDLEventFired()
{
	return sdlwrap_.quitEventCheck();
}