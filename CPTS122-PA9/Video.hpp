#ifndef VIDEOM
#define VIDEOM

#include "Menu.hpp"

class Video : public Menu
{
public:
	typedef enum videoresult
	{
		BACK
	}VideoResult;

	// Member Functions
	MenuResult show(sf::RenderWindow& window);
	//VideoResult show(sf::RenderWindow& window);

};

#endif // !VIDEOM
