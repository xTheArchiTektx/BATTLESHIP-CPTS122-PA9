#ifndef CONTROLSM
#define CONTROLSM

#include "Menu.hpp"

class Controls : public Menu
{
public:
	typedef enum controlsresult
	{
		BACK
	}ControlsResult;

	// Member Functions
	MenuResult show(sf::RenderWindow& window);
	//ControlsResult show(sf::RenderWindow& window);

};

#endif // !CONTROLSM
