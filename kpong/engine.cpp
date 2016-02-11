#include <stdlib.h>
#include <ctime>

#include "engine.h"
#include "kpongdef.h"
#include "collisionmgr.h"

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
	sdlwrap_.clearScreen();
	mapGWO_.clear();
}

void PongEngine::quitgame()
{
	sdlwrap_.quitSDL();
}

void PongEngine::processKeys()
{
	// Get keyboard event
	int key = sdlwrap_.processKeys();
	int x = 0, y = 0;

	if (0 != key)
	{
		// Clear screen before redraw
		sdlwrap_.clearScreen();

		// Player move up
		if (KEY_w == key)
		{
			mapGWO_[gwo_type::player].getPos(x, y);

			if (PADDING < y)
				mapGWO_[gwo_type::player].setPos(x, y - MOVE_STEP * PADDLE_SPEED);
		}

		// Player move down
		if (KEY_s == key)
		{
			mapGWO_[gwo_type::player].getPos(x, y);

			if (SCREEN_HEIGHT > (y + PLAYER_HEIGHT + 20))
				mapGWO_[gwo_type::player].setPos(x, y + MOVE_STEP * PADDLE_SPEED);
		}
		
		// ai move up
		if (KEY_UP == key)
		{
			mapGWO_[gwo_type::ai].getPos(x, y);

			if (PADDING < y)
				mapGWO_[gwo_type::ai].setPos(x, y - MOVE_STEP * PADDLE_SPEED);
		}

		// Player move down
		if (KEY_DOWN == key)
		{
			mapGWO_[gwo_type::ai].getPos(x, y);

			if (SCREEN_HEIGHT > (y + PLAYER_HEIGHT + 20))
				mapGWO_[gwo_type::ai].setPos(x, y + MOVE_STEP * PADDLE_SPEED);
		}

	}
}

void PongEngine::logic()
{
	// Move ball
	moveball();
}

void PongEngine::drawscreen()
{
	drawGWOs();

	sdlwrap_.renderScreen();
}

void PongEngine::pollevent()
{
	sdlwrap_.pollevent();
}

bool PongEngine::quitSDLEventFired()
{
	return sdlwrap_.quitEventCheck();
}

void PongEngine::addGWOs()
{
	GWO	player, ai, ball;

	player.setDimensions(PLAYER_WIDTH, PLAYER_HEIGHT);
	player.setPos(PADDING, (SCREEN_HEIGHT / 2) - (PLAYER_HEIGHT / 2));
	player.setType(gwo_type::player);

	ai.setDimensions(AI_WIDTH, AI_HEIGHT);
	ai.setPos((SCREEN_WIDTH - AI_WIDTH) - PADDING, (SCREEN_HEIGHT / 2) - (AI_HEIGHT / 2));
	ai.setType(gwo_type::ai);

	ball.setDimensions(BALL_SIDE, BALL_SIDE);
	ball.setPos((SCREEN_WIDTH / 2) - (BALL_SIDE / 2), (SCREEN_HEIGHT / 2) - (BALL_SIDE / 2));
	ball.setType(gwo_type::ball);

	mapGWO_[gwo_type::player] = player;
	mapGWO_[gwo_type::ai] = ai;
	mapGWO_[gwo_type::ball] = ball;

	resetBall();
}

void PongEngine::drawGWOs()
{
	std::map<gwo_type, GWO>::iterator it = mapGWO_.begin();
	
	GWO gameobj;
	int x, y, w, h;

	while (it != mapGWO_.end())
	{
		gameobj = it->second;
		gameobj.getDimensions(w, h);
		gameobj.getPos(x, y);

		sdlwrap_.drawRect(x, y, w, h);

		it++;
	}
}

void PongEngine::moveball()
{
	int xVel = 0, yVel = 0;
	int x = 0, y = 0;
	CollisionMgr collision;

	// Clear screen
	sdlwrap_.clearScreen();

	// Get ball position
	mapGWO_[gwo_type::ball].getPos(x, y);
	
	// Get ball velocity
	mapGWO_[gwo_type::ball].getVel(xVel, yVel);
	
	// Bounce ball from walls
	if ((y < 1) || (y + BALL_SIDE > SCREEN_HEIGHT))
	{
		yVel = -yVel;
		mapGWO_[gwo_type::ball].setVel(xVel, yVel); // Update new y velocity
	}

	// Check if ball collides with paddles 
	if (collision.checkCollision(mapGWO_[gwo_type::ball], mapGWO_[gwo_type::player]) ||
		collision.checkCollision(mapGWO_[gwo_type::ball], mapGWO_[gwo_type::ai]))
	{
		xVel = -xVel;
		mapGWO_[gwo_type::ball].setVel(xVel, yVel); 
	}
	
	// Adjust velocity of ball
	x += xVel;
	y += yVel;

	if ((x < 1) || (x > SCREEN_WIDTH - (BALL_SIDE + PADDING)))
	{
		resetBall();
		return;
	}

	// Adjust position of ball
	mapGWO_[gwo_type::ball].setPos(x, y);
}

void PongEngine::resetBall()
{
	mapGWO_[gwo_type::ball].setPos((SCREEN_WIDTH / 2) - (BALL_SIDE / 2), (SCREEN_HEIGHT / 2) - (BALL_SIDE / 2));

	srand(time(NULL));

	int xVel = rand() % SEED_HIGH + SEED_LOW;
	int yVel = rand() % SEED_HIGH + SEED_LOW;

	// Set random x and y velocity
	mapGWO_[gwo_type::ball].setVel(xVel, yVel);
}

unsigned int PongEngine::getTicks()
{
	return sdlwrap_.getTicks();
}