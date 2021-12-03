#ifndef OPTIONS
#define OPTIONS

#include "Menu.hpp"

class Options : public Menu
{
public:
	typedef enum optionsresult
	{
		BACK, CONTROLS, RULES, VIDEO, AUDIO
	}OptionsResult;

		// Member Functions
	MenuResult show(sf::RenderWindow& window);
	//OptionsResult show(sf::RenderWindow& window);
};

#endif // !OPTIONS
