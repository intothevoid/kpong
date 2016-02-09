#pragma once

#include "gameobject.h"

class CollisionMgr
{
public:
	CollisionMgr();
	~CollisionMgr();
	bool checkCollision(GWO obj1, GWO obj2);

private:
	bool pointInRect(int x, int y, GWO obj);
};

