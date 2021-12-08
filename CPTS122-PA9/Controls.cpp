#include "Controls.hpp"

Menu::MenuResult Controls::show(sf::RenderWindow& window)
{
	// Load and texture from file.
	mMenuT.loadFromFile("images/controlsmenu.png");

	/** Setup clickable regions **/

		// Audio menu item coordinates
	MenuItem audioButton;
	audioButton.mRect.top = 136;
	audioButton.mRect.height = 36; // bottom - top
	audioButton.mRect.left = 120;
	audioButton.mRect.width = 90; // right - left
	audioButton.action = AUDIO;

	// Rules item coordinates
	MenuItem rulesButton;
	rulesButton.mRect.top = 136;
	rulesButton.mRect.height = 36;
	rulesButton.mRect.left = 362;
	rulesButton.mRect.width = 90;
	rulesButton.action = RULES;

	// Back item coordinates
	MenuItem backButton;
	backButton.mRect.top = 457;
	backButton.mRect.height = 13;
	backButton.mRect.left = 360;
	backButton.mRect.width = 100;
	backButton.action = BACK;

	// Add the buttons to the list.
	mMenuItems.push_back(audioButton);
	mMenuItems.push_back(rulesButton);
	mMenuItems.push_back(backButton);

	// Display the texture to the screen.
	mMenuScreen.setTexture(mMenuT);
	window.draw(mMenuScreen);
	window.display();

	return GetMenuResponse(window);
}