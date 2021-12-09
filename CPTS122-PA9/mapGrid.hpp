#pragma once
#include "PA9.hpp"

class Grid
{
public:
	enum gridCondition { OCCUPIED, HIT, EMPTY, MISS };
	//constructor
	Grid()
	{
		xCord = 0;
		yCord = 0;
		currCondition = EMPTY;
	}
	//Copy Constructor
	Grid(const Grid& newGrid)
	{
		xCord = newGrid.xCord;
		yCord = newGrid.yCord;
		currCondition = newGrid.currCondition;
	}
	//Destructor
	~Grid() {};
	//Setters
	void setX(int newX) { xCord = newX; };
	void setY(int newY) { yCord = newY; };
	void setCondition(gridCondition newCondition) { currCondition = newCondition; };
	//getters
	int getX(void) { return xCord; };
	int getY(void) { return yCord; };
	gridCondition getCurrentCond(void) { return currCondition; };

	//Member Functions
private:
	int xCord;
	int yCord;
	gridCondition currCondition;
};


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
	int getXLocation(void) { return pixLocationX; };
	int getYLocation(void) { return pixLocationY; };
	int getXScale(void) { return xScale; };
	int getYScale(void) { return yScale; };
	Grid* getGridArray(void) { return *gridArray; };

	//Member Functions
	void intilizeGrid(void);
	Grid& getTargetGrid(int xCord, int yCord) { return gridArray[xCord - 1][yCord - 1]; };
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

BoardGrid::BoardGrid()
{
}

BoardGrid::~BoardGrid()
{
}

void BoardGrid::intilizeGrid(void)
{
	int i = 0, j = 0, count = 0;
	while (i <= 0)//Row - Y value 
	{
		while (j <= 0)//Column - X Value
		{
			gridArray[i][j].setX(j + 1);
			gridArray[i][j].setY(i + 1);
			gridArray[i][j].setCondition(Grid::EMPTY);
			j++;
		}
		j = 0;
		i++;
	}
}
