#pragma once
#include "PA9.hpp"
#include "Ship.hpp"
#include "shipCordList.hpp"
Ship::Ship()
{
	this->gridLength = 0;
	this->numHits = 0;
	this->pixLength = 0;
	this->pixWidth = 0;
	this->shipName = "";
}


Ship::Ship(int newGridLength, int newHits, int newPixWidth,
	int newPixLength, std::string newName,
	sf::Color newColor)
{
	this->gridLength = newGridLength;
	this->numHits = newHits;
	this->pixWidth = newPixWidth;
	this->pixLength = newPixLength;
	this->shipColor = newColor;
	//this->shipCoordinates = newList;
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
	this->shipColor = newShip.shipColor;
}

//Ship& Ship::operator=(Ship& rhs)
//{
//	this->gridLength = rhs.gridLength;
//	this->numHits = rhs.numHits;
//	this->pixLength = rhs.pixLength;
//	this->pixWidth = rhs.pixWidth;
//	this->shipName = rhs.shipName;
//	this->shipCoordinates = rhs.shipCoordinates;
//	this->shipColor = rhs.shipColor;
//	return *this;
//}