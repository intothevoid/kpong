#include "engine.h"
#include "kpongdef.h"

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

void PongEngine::addgwos()
{
	GWO	player, ai, ball;

	player.setDimensions(PLAYER_WIDTH, PLAYER_HEIGHT);
	player.setPos(1, (SCREEN_HEIGHT / 2) - (PLAYER_HEIGHT / 2));
	player.setType(gwo_type::player);

	ai.setDimensions(AI_WIDTH, AI_HEIGHT);
	ai.setPos((SCREEN_WIDTH - AI_WIDTH) - 1, (SCREEN_HEIGHT / 2) - (AI_HEIGHT / 2));
	ai.setType(gwo_type::ai);

	ball.setDimensions(BALL_SIDE, BALL_SIDE);
	ball.setPos((SCREEN_WIDTH / 2) - (BALL_SIDE / 2), (SCREEN_HEIGHT / 2) - (BALL_SIDE / 2));
	ball.setType(gwo_type::ball);

	vecGWO_.push_back(player);
	vecGWO_.push_back(ai);
	vecGWO_.push_back(ball);
}