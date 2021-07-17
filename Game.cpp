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
			grid[i][j] = new Cell(i * 10, j * 10, 10, 10, false);
		}
	}
}

void Game::switchCellState(int x, int y)
{
	grid[x][y]->switchState();
}

void Game::update()
{
	Cell*** gridCopy = new Cell * *[width];
	for (int i = 0; i < width; i++)
	{
		gridCopy[i] = new Cell * [height];
		for (int j = 0; j < height; j++)
		{
			gridCopy[i][j] = new Cell(*grid[i][j]);
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int count = getLiveNeighbours(i, j, gridCopy);
			if (gridCopy[i][j]->isAlive())
			{
				if (count < 2)
				{
					grid[i][j]->switchState();
				}
				else if (count > 3)
				{
					grid[i][j]->switchState();
				}
			}
			else
			{
				if (count == 3)
				{
					grid[i][j]->switchState();
				}
			}
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			free(gridCopy[i][j]);
		}
		free(gridCopy[i]);
	}
	free(gridCopy);
}

void Game::draw(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			grid[i][j]->draw(gRenderer, simulationIsRunning);
		}
	}
}

int Game::getLiveNeighbours(int x, int y, Cell*** gridCopy)
{
	int count = 0;

	bool xIsNotZero = x != 0;
	bool xIsNotWidth = x != width - 1;
	bool yIsNotZero = y != 0;
	bool yIsNotHeight = y != height - 1;

	if (xIsNotZero)
	{
		if (gridCopy[x - 1][y]->isAlive())
		{
			count++;
		}
	}
	if (xIsNotWidth)
	{
		if (gridCopy[x + 1][y]->isAlive())
		{
			count++;
		}
	}
	if (yIsNotZero)
	{
		if (gridCopy[x][y - 1]->isAlive())
		{
			count++;
		}
	}
	if (yIsNotHeight)
	{
		if (gridCopy[x][y + 1]->isAlive())
		{
			count++;
		}
	}
	if (xIsNotZero && yIsNotZero)
	{
		if (gridCopy[x - 1][y - 1]->isAlive())
		{
			count++;
		}
	}
	if (xIsNotZero && yIsNotHeight)
	{
		if (gridCopy[x - 1][y + 1]->isAlive())
		{
			count++;
		}
	}
	if (xIsNotWidth && yIsNotZero)
	{
		if (gridCopy[x + 1][y - 1]->isAlive())
		{
			count++;
		}
	}
	if (xIsNotWidth && yIsNotHeight)
	{
		if (gridCopy[x + 1][y + 1]->isAlive())
		{
			count++;
		}
	}

	return count;
}

void Game::clear()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (grid[i][j]->isAlive())
			{
				grid[i][j]->switchState();
			}
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

bool Game::simulationRunning()
{
	return simulationIsRunning;
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

void Game::setSimulationStatus(bool s)
{
	simulationIsRunning = s;
}