#include "collisionmgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::pointInRect(int x, int y, GWO obj)
{
	int x1 = 0, y1 = 0;
	int h1 = 0, w1 = 0;

	obj.getPos(x1, y1);
	obj.getDimensions(w1, h1);

	if (x > x1 &&
		y > y1 &&
		x < x1 + w1 &&
		y < y1 + h1)
	{
		return true;
	}

	return false;
}
	
bool CollisionMgr::checkCollision(GWO obj1, GWO obj2)
{
	int x1 = 0, y1 = 0;
	int h1 = 0, w1 = 0;

	obj1.getPos(x1, y1);
	obj1.getDimensions(w1, h1);

	if (pointInRect(x1, y1, obj2) ||
		pointInRect(x1 + w1, y1, obj2) ||
		pointInRect(x1, y1 + h1, obj2) ||
		pointInRect(x1 + w1, y1 + h1, obj2))
	{
		return true;
	}

	return false;
}
