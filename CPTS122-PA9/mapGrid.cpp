#include "mapGrid.hpp"

Grid::Grid()
{
	xCord = 0;
	yCord = 0;
	currCondition = EMPTY;
}

Grid::Grid(const Grid& newGrid)
{
xCord = newGrid.xCord;
yCord = newGrid.yCord;
currCondition = newGrid.currCondition;
}

Grid::~Grid()
{

}

void Grid::setX(int newX)
{ 
	xCord = newX; 
}

void Grid::setY(int newY)
{ 
	yCord = newY; 
}

void Grid::setCondition(Grid::GridCondition newCondition)
{ 
	currCondition = newCondition;
}

int Grid::getX(void) 
{ 
	return xCord; 
}

int Grid::getY(void) 
{ 
	return yCord; 
}

Grid::GridCondition Grid::getCurrentCond(void) 
{ 
	return currCondition; 
}