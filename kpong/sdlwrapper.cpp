#include "sdlwrapper.h"
#include "kpongdef.h"

SDL_Window* screen;
SDL_Event occur;

SDLWrapper::SDLWrapper()
{
}

SDLWrapper::~SDLWrapper()
{
}

void SDLWrapper::initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
}

void SDLWrapper::quitSDL()
{
	TTF_Quit();
	SDL_Quit();
}

void SDLWrapper::createwindow()
{
	screen = SDL_CreateWindow("KPong - Pong in black and white",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_SWSURFACE);
}

void SDLWrapper::pollevent()
{
	SDL_PollEvent(&occur);
}

bool SDLWrapper::quitEventCheck()
{
	return (occur.type == SDL_QUIT ? true : false);
}