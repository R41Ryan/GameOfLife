#pragma once

class Cell 
{
private:
	int xPos;
	int yPos;
	int width;
	int height;
	bool liveState;
public:
// Constructors
	Cell();
	Cell(int x, int y, int w, int h);
	Cell(int x, int y, int w, int h, bool s);

// Functions
	// if isAlive is true, set to false, and vice versa.
	void switchState();

// Getter Functions
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	bool isAlive();

// Setter Functions;
	void setX(int x);
	void setY(int y);
	void setWidth(int w);
	void setHeight(int h);
};