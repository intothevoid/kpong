#include "gameobject.h"

GWO::GWO()
{
}

GWO::~GWO()
{
}

void GWO::setType(gwo_type type)
{
	type_ = type;
}

gwo_type GWO::getType()
{
	return type_;
}

void GWO::setPos(int x, int y)
{
	x_ = x;
	y_ = y;
}

void GWO::getPos(int& x, int& y)
{
	x = x_;
	y = y_;
}
void GWO::setDimensions(int w, int h)
{
	w_ = w;
	h_ = h;
}
void GWO::getDimensions(int& w, int& h)
{
	w = w_;
	h = h_;
}
