#pragma once

#include "PA9.hpp"

class Grid
{
public:
	typedef enum gridcondition 
	{ 
		OCCUPIED, HIT, EMPTY, MISS 
	}GridCondition;

	//constructor
	Grid();

	//Copy Constructor
	Grid(const Grid& newGrid);

	//Destructor
	~Grid();

	//Setters
	void setX(int newX);
	void setY(int newY);
	void setCondition(GridCondition newCondition);

	//getters
	int getX(void);
	int getY(void);
	GridCondition getCurrentCond(void);

	//Member Functions
private:
	int xCord;
	int yCord;
	GridCondition currCondition;
};



