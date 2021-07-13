#include <Game.h>

int Game::getCellNum()
{
	return cellNum;
}

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

Cell*** Game::getGrid()
{
	return grid;
}

void Game::setCellNum(int n)
{
	cellNum = n;
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

void Game::setGrid(Cell*** g)
{
	grid = g;
}