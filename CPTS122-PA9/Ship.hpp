#pragma once
#include "PA9.hpp"

class Ship
{
public:
	//constructor
	Ship();
	//destructor

	//setters
	int getLength(void);
	int getHits(void);
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




protected:

};