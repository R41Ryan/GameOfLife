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
// Functions

// Getter Functions
	int getCellNum();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	Cell*** getGrid();
// Setter Functions
};