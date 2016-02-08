#pragma once

#include "kpongdef.h"

class GWO
{
private:
	int x_, y_, h_, w_;
	int xVel_, yVel_;
	gwo_type type_;
public:
	GWO();
	~GWO();
	void setType(gwo_type type);
	gwo_type getType();
	void setPos(int x, int y);
	void getPos(int& x, int& y);
	void setDimensions(int w, int h);
	void getDimensions(int& w, int& h);
	void setVel(int xVel, int yVel);
	void getVel(int& xVel, int& yVel);
};

