#ifndef SHIPS_MENU
#define SHIPS_MENU

#include "Menu.hpp"

class ShipsMenu : public Menu
{
public:
		// Member Functions
	MenuResult show(sf::RenderWindow& window);
	void displayCarrier(sf::RenderWindow& window);
	void displayBattleship(sf::RenderWindow& window);
	void displayDestroyer(sf::RenderWindow& window);
	void displaySubmarine(sf::RenderWindow& window);
	void displayPatrolBoat(sf::RenderWindow& window);
};

#endif // !OPTIONS
