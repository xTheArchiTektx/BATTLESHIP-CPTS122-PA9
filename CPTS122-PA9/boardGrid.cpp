#include "boardGrid.hpp"

BoardGrid::BoardGrid()
{

}

BoardGrid::~BoardGrid()
{

}

int BoardGrid::getXScale(void) 
{ 
	return xScale; 
}

int BoardGrid::getYScale(void)
{ 
	return yScale; 
}

Grid* BoardGrid::getGridArray(void)
{ 
	return *gridArray; 
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

Grid& BoardGrid::getTargetGrid(int xCord, int yCord)
{ 
	return gridArray[xCord - 1][yCord - 1]; 
}