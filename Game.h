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
	Cell** grid[];
public:
// Constructors
	Game();
	Game(int x, int y);
	Game(int x, int y, int w, int h);
	Game(int x, int y, int w, int h);
// Functions

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
	void setGrid(Cell** g[]);
};