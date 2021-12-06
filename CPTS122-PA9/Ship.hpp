#pragma once
#include "PA9.hpp"

class Ship
{
public:
	//constructor
	Ship();
	//destructor

	//setters
	int getLength(void) { return length; };
	int getHits(void) { return numHits; };
	//getters

	//member functions

private:
	//graphics properties:
	int pixLength;
	int pixWidth;
	sf::Color shipColor;

	//ship properties
	std::string shipName;
	int length;
	std::list<int> shipCoordinates;
	int numHits;



protected:

};