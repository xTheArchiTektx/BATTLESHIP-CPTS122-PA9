/***********************************************\
|												|
|												|
|												|
|												|
\***********************************************/

#ifndef MENU
#define MENU

#include "PA9.hpp"

class Menu
{
public:
	// Data Types
	typedef enum menuresult
	{
		NOTHING, EXIT, PLAY
	}MenuResult;

	typedef struct menuitem
	{
	public:
		sf::Rect<int> mRect;
		MenuResult action;
	}MenuItem;

private:
	// Data Members
	std::list<MenuItem> mMenuItems;

	// Member Functions
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);

public:
	// Member Functions
	MenuResult show(sf::RenderWindow& window);

};

#endif // !MENU
