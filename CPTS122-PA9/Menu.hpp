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
	Texture mMenuT;
	Sprite mMenuScreen;

	// Member Functions
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);

public:
	// Member Functions
	virtual MenuResult show(sf::RenderWindow& window);

};

#endif // !MENU
