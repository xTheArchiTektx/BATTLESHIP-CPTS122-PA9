#ifndef AUDIOM
#define AUDIOM

#include "Menu.hpp"

class Audio : public Menu
{
public:
	typedef enum audioresult
	{
		BACK
	}AudioResult;

	// Member Functions
	MenuResult show(sf::RenderWindow& window);
	//AudioResult show(sf::RenderWindow& window);

};

#endif // !AUDIOM
