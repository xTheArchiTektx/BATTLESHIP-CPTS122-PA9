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
		int newPixLength, std::string newName,
		sf::Color newColor);
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
	void setColor(sf::Color newColor) { shipColor = newColor; };
	void setTexture(Texture shipTexture) { shipImage.setTexture(shipTexture); };

	//getters
	int getGridLength(void) { return gridLength; };
	int getHits(void) { return numHits; };
	Sprite getSprite(void) { return shipImage; };
	ShipCordList getCordinates(void) { return shipCoordinates; };
	std::string getName(void) { return shipName; };
	int getPixLength(void) { return pixLength; };
	int getPixWidth(void) { return pixWidth; };
	sf::Color getColor(void) { return shipColor; };
	//member functions
	void setCorrdinates(Direction placement, int start_x, int start_y);

//	Ship& operator=(const Ship& rhs);
private:
	std::string shipName;
	Sprite shipImage;
	int pixLength;
	int pixWidth;
	int gridLength;
	sf::Color shipColor;
	int numHits;
	ShipCordList shipCoordinates;
	//std::list<int> shipCoordinates;
	
protected:

};