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



