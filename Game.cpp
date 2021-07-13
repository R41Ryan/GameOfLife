#include <Game.h>

int Game::getX()
{
	return xPos;
}

int Game::getY()
{
	return yPos;
}

int Game::getWidth()
{
	return width;
}

int Game::getHeight()
{
	return height;
}

void Game::setX(int x)
{
	xPos = x;
}

void Game::setY(int y)
{
	yPos = y;
}

void Game::setWidth(int w)
{
	width = w;
}

void Game::setHeight(int h)
{
	height = h;
}
