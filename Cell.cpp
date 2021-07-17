#include <Cell.h>

Cell::Cell()
{
	xPos = 0;
	yPos = 0;
	width = 10;
	height = 10;
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

Cell::Cell(const Cell &copy)
{
	setX(copy.xPos);
	setY(copy.yPos);
	setWidth(copy.width);
	setHeight(copy.height);
	liveState = copy.liveState;
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

void Cell::draw(SDL_Renderer* gRenderer, bool simulationIsRunning)
{
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
	SDL_Rect drawRect = { xPos, yPos, width, height };
	if (isAlive())
	{
		SDL_RenderFillRect(gRenderer, &drawRect);
	}
	else if (!simulationIsRunning)
	{
		SDL_RenderDrawRect(gRenderer, &drawRect);
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
