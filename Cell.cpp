#include <Cell.h>

Cell::Cell()
{
	xPos = 0;
	yPos = 0;
	width = 5;
	height = 5;
	liveState = false;
}

Cell::Cell(int x, int y, int w, int h)
{
	setX(x);
	setY(y);
	setWidth(w);
	setHeight(h);
	liveState = false;
}

Cell::Cell(int x, int y, int w, int h, bool s)
{
	setX(x);
	setY(y);
	setWidth(w);
	setHeight(h);
	liveState = s;
}

void Cell::switchState()
{
	if (liveState == false)
	{
		liveState = true;
	}
	else
	{
		liveState = false;
	}
}

int Cell::getX()
{
	return xPos;
}

int Cell::getY()
{
	return yPos;
}

int Cell::getWidth()
{
	return width;
}

int Cell::getHeight()
{
	return height;
}

bool Cell::isAlive()
{
	return liveState;
}

void Cell::setX(int x)
{
	xPos = x;
}

void Cell::setY(int y)
{
	yPos = y;
}

void Cell::setWidth(int w)
{
	width = w;
}

void Cell::setHeight(int h)
{
	height = h;
}
