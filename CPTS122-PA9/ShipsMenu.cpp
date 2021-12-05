#include "ShipsMenu.hpp"
Menu::MenuResult ShipsMenu::show(sf::RenderWindow& window)
{
		// Load and texture from file.
	mMenuT.loadFromFile("images/shipmenu.png");

	/** Setup clickable regions **/

		// Carrier item coordinates.
	MenuItem carrier;
	carrier.mRect.top = 160;
	carrier.mRect.height = 60; // bottom - top
	carrier.mRect.left = 275;
	carrier.mRect.width = 225; // right - left
	carrier.action = CARRIER;

		// Battleship item coordinates.
	MenuItem battleship;
	battleship.mRect.top = 240;
	battleship.mRect.height = 60; // bottom - top
	battleship.mRect.left = 275;
	battleship.mRect.width = 225; // right - left
	battleship.action = BATTLESHIP;

		// Submarine item coordinates.
	MenuItem submarine;
	submarine.mRect.top = 320;
	submarine.mRect.height = 60; // bottom - top
	submarine.mRect.left = 275;
	submarine.mRect.width = 225; // right - left
	submarine.action = SUB;

		// Cruiser item coordinates.
	MenuItem cruiser;
	cruiser.mRect.top = 400;
	cruiser.mRect.height = 60; // bottom - top
	cruiser.mRect.left = 275;
	cruiser.mRect.width = 225; // right - left
	cruiser.action = CRUISER;

	// Destroyer item coordinates.
	MenuItem destroyer;
	destroyer.mRect.top = 400;
	destroyer.mRect.height = 60; // bottom - top
	destroyer.mRect.left = 275;
	destroyer.mRect.width = 225; // right - left
	destroyer.action = DESTROYER;

		// Add the buttons to the list.
	mMenuItems.push_back(cruiser);
	mMenuItems.push_back(battleship);
	mMenuItems.push_back(submarine);
	mMenuItems.push_back(carrier);
	mMenuItems.push_back(destroyer);

		// Display the texture to the screen.
	mMenuScreen.setTexture(mMenuT);
	window.draw(mMenuScreen);
	window.display();

	return GetMenuResponse(window);
}
