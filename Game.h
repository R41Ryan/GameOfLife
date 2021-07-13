#pragma once
#include <Cell.h>

class Game
{
private:
	int cellNum;
	int xPos;
	int yPos;
	int width;
	int height;
	Cell*** grid;

	bool simulationIsRunning;
public:
// Constructors
	Game(int n);
	Game(int n, int x, int y);
	Game(int n, int x, int y, int w, int h);

// Functions
	// Updates the state of each cell, based on the number of surrounding live cells;
	void update();

// Getter Functions
	int getCellNum();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	Cell*** getGrid();

// Setter Functions
	void setCellNum(int n);
	void setX(int x);
	void setY(int y);
	void setWidth(int w);
	void setHeight(int y);
	void setGrid(Cell*** g);
};