#include "ShipsMenu.hpp"
Menu::MenuResult ShipsMenu::show(sf::RenderWindow& window)
{
		// Load and texture from file.
	mMenuT.loadFromFile("images/shipmenu.png");

	/** Setup clickable regions **/

		// Confirm button coordinates
	MenuItem confirm;
	confirm.mRect.top = 460;
	confirm.mRect.height = 15; // bottom - top
	confirm.mRect.left = 330;
	confirm.mRect.width = 95; // right - left
	confirm.action = CONFIRM;

		// Carrier item coordinates.
	MenuItem carrier;
	carrier.mRect.top = 148;
	carrier.mRect.height = 27; // bottom - top
	carrier.mRect.left = 99;
	carrier.mRect.width = 131; // right - left
	carrier.action = CARRIER;

		// Battleship item coordinates.
	MenuItem battleship;
	battleship.mRect.top = 219;
	battleship.mRect.height = 27; // bottom - top
	battleship.mRect.left = 98;
	battleship.mRect.width = 106; // right - left
	battleship.action = BATTLESHIP;

		// Submarine item coordinates.
	MenuItem submarine;
	submarine.mRect.top = 364;
	submarine.mRect.height = 27; // bottom - top
	submarine.mRect.left = 102;
	submarine.mRect.width = 78; // right - left
	submarine.action = SUB;

		// Patrol Boat item coordinates.
	MenuItem patrolBoat;
	patrolBoat.mRect.top = 400;
	patrolBoat.mRect.height = 27; // bottom - top
	patrolBoat.mRect.left = 275;
	patrolBoat.mRect.width = 225; // right - left
	patrolBoat.action = PATROL_BOAT;

	// Destroyer item coordinates.
	MenuItem destroyer;
	destroyer.mRect.top = 291;
	destroyer.mRect.height = 27; // bottom - top
	destroyer.mRect.left = 101;
	destroyer.mRect.width = 78; // right - left
	destroyer.action = DESTROYER;

		// Add the buttons to the list.
	mMenuItems.push_back(confirm);
	mMenuItems.push_back(patrolBoat);
	mMenuItems.push_back(battleship);
	mMenuItems.push_back(submarine);
	mMenuItems.push_back(carrier);
	mMenuItems.push_back(destroyer);

		// Display the texture to the screen.
	mMenuScreen.setTexture(mMenuT);
	window.draw(mMenuScreen);
	window.display();

	GetMenuResponse(window);
}

void ShipsMenu::displayCarrier(sf::RenderWindow& window)
{
	Font font;
	font.loadFromFile("fonts/BlackOpsOne-Regular.ttf");
	Text l1;
	l1.setFont(font);
	l1.setString("Ship: Aircraft Carrier\nHits: 5\nDescription: ");
	window.draw(l1);
	window.display();
}

void ShipsMenu::displayBattleship(sf::RenderWindow& window)
{
	Font font;
	font.loadFromFile("fonts/BlackOpsOne-Regular.ttf");
	Text l1;
	l1.setFont(font);
	l1.setString("Ship: Battleship\nHits: 4\nDescription: ");
	window.draw(l1);
	window.display();
}

void ShipsMenu::displayDestroyer(sf::RenderWindow& window)
{
	Font font;
	font.loadFromFile("fonts/BlackOpsOne-Regular.ttf");
	Text l1;
	l1.setFont(font);
	l1.setString("Ship: Destroyer\nHits: 3\nDescription: ");
	window.draw(l1);
	window.display();
}

void ShipsMenu::displaySubmarine(sf::RenderWindow& window)
{
	Font font;
	font.loadFromFile("fonts/BlackOpsOne-Regular.ttf");
	Text l1;
	l1.setFont(font);
	l1.setString("Ship: Submarine\nHits: 3\nDescription: ");
	window.draw(l1);
	window.display();
}

void ShipsMenu::displayPatrolBoat(sf::RenderWindow& window)
{
	Font font;
	font.loadFromFile("fonts/BlackOpsOne-Regular.ttf");
	Text l1;
	l1.setFont(font);
	l1.setString("Ship: Patrol Boat\nHits: 2\nDescription: ");
	window.draw(l1);
	window.display();
}