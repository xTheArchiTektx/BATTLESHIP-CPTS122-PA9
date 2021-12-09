#pragma once

#include "mapGrid.hpp"

class BoardGrid
{
public:
	enum Player { Player1, Player2 };
	//Constructor
	BoardGrid();
	//Destructor
	~BoardGrid();
	//Setters

	//Getters
	//int getXLocation(void) { return pixLocationX; };
	//int getYLocation(void) { return pixLocationY; };
	int getXScale(void);
	int getYScale(void);
	Grid* getGridArray(void);

	//Member Functions
	void intilizeGrid(void);
	Grid& getTargetGrid(int xCord, int yCord);
	const int pixLocationX = 96;
	const int pixLocationY = 107;
private:
	//Location of upperLeft Pixel/Start of GameBoard

	//Size of game board window in pixels
	const int xScale = 277;
	const int yScale = 277;
	//GameGrid Array:
	Grid gridArray[10][10];

};