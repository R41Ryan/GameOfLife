#include <Game.h>
#include <iostream>
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_rect.h>

Game::Game(int x, int y, int w, int h)
{
	xPos = x;
	yPos = y;
	width = w;
	height = h;

	simulationIsRunning = false;
	cellNum = w * h;

	grid = new Cell * *[w];
	for (int i = 0; i < w; i++)
	{
		grid[i] = new Cell * [h];
		for (int j = 0; j < h; j++)
		{
			grid[i][j] = new Cell(i * 10, j * 10, 10, 10);
		}
	}
}

void Game::switchCellState(int x, int y)
{
	grid[x][y]->switchState();
}

void Game::update()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int count;
			if (i != 0)
			{

			}
		}
	}
}

void Game::draw(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			grid[i][j]->draw(gRenderer);
		}
	}
}

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