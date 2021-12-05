#ifndef AUDIOM
#define AUDIOM

#include "Menu.hpp"

class Audio : public Menu
{
public:
	// Member Functions
	MenuResult show(sf::RenderWindow& window);
};

#endif // !AUDIOM
