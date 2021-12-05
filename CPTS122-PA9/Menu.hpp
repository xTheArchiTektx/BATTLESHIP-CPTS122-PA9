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
		NOTHING, EXIT, PLAY, OPTION, CREDIT, PLAYER_1, PLAYER_2, CARRIER, BATTLESHIP, CRUISER, SUB, DESTROYER,BACK, CONTROLS, RULES, AUDIO
	}MenuResult;

	typedef struct menuitem
	{
	public:
		sf::Rect<int> mRect;
		MenuResult action;
	}MenuItem;

protected:
	// Data Members
	std::list<MenuItem> mMenuItems;
	Texture mMenuT;
	Sprite mMenuScreen;

	// Member Functions
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	void loadPlayerButtons(RenderWindow& window);

public:
	// Member Functions
	virtual MenuResult show(sf::RenderWindow& window, int& playerCount);

};

#endif // !MENU
