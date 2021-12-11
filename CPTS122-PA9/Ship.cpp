#include "Ship.hpp"


Ship::Ship()
{
	this->gridLength = 0;
	this->numHits = 0;
	this->pixLength = 0;
	this->pixWidth = 0;
	this->shipName = "";
}


Ship::Ship(int newGridLength, int newHits, int newPixWidth,
	int newPixLength, std::string newName)
{
	this->gridLength = newGridLength;
	this->numHits = newHits;
	this->pixWidth = newPixWidth;
	this->pixLength = newPixLength;
	this->shipName = newName;
}


Ship::Ship(const Ship& newShip) 
{
	this->gridLength = newShip.gridLength;
	this->numHits = newShip.numHits;
	this->pixLength = newShip.pixLength;
	this->pixWidth = newShip.pixWidth;
	this->shipName = newShip.shipName;
	this->shipCoordinates = newShip.shipCoordinates;
	this->shipImage = newShip.shipImage;

}

void Ship::setCorrdinates(Direction placement, int start_x, int start_y)
{
	switch (placement)
	{
	case RIGHT:
		for (int i = 0; i < gridLength; i++)
		{
			CordListNode* newNode = new CordListNode(start_x + i, start_y);
			this->shipCoordinates.insert(newNode);
		}
		break;
	case UP:
		for (int i = 0; i < gridLength; i++)
		{
			CordListNode* newNode = new CordListNode(start_x, start_y-i);
			this->shipCoordinates.insert(newNode);
		}
		break;
	}

	this->shipImage.setPosition(sf::Vector2f((float)(96 + 28 * (start_x - 1)),(float)( 107 + 28 * (start_y - 1))));
}