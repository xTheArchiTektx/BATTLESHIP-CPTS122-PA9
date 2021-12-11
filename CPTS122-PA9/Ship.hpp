#pragma once
#include "PA9.hpp"
#include "shipCordList.hpp"

class Ship
{
public:
	typedef enum direction
	{
		UP,RIGHT
	}Direction;

	//constructor
	Ship();

	//Constructor w/ Values
	Ship(int newGridLength, int newHits, int newPixWidth,
		int newPixLength, std::string newName);

	//cpy constructor
	Ship(const Ship& newShip);

	//destructor
	~Ship() {};

	//setters
	void setGridLength(int newLength) { gridLength = newLength; };
	void setHitNum(int newHit) { numHits = newHit; };
	void setCordList(ShipCordList newList) { shipCoordinates = newList; };
	void setName(std::string newName) { shipName = newName; };
	void setPixLength(int newPixL) { pixLength = newPixL; };
	void setPixWidth(int newPixW) { pixWidth = newPixW; };
	void setTexture(string shipTexture) 
	{ 
		shipT.loadFromFile(shipTexture);
		shipImage.setTexture(shipT); 
	};

	//getters
	int getGridLength(void) { return gridLength; };
	int getHits(void) { return numHits; };
	Sprite getSprite(void) { return shipImage; };
	ShipCordList getCordinates(void) { return shipCoordinates; };
	std::string getName(void) { return shipName; };
	int getPixLength(void) { return pixLength; };
	int getPixWidth(void) { return pixWidth; };

	//member functions
	void setCorrdinates(Direction placement, int start_x, int start_y);

private:
	std::string shipName;
	Texture shipT;
	Sprite shipImage;
	int pixLength;
	int pixWidth;
	int gridLength;
	int numHits;
	ShipCordList shipCoordinates;
};