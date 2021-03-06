#include "Audio.hpp"

Menu::MenuResult Audio::show(sf::RenderWindow& window)
{
	// Load and texture from file.
	mMenuT.loadFromFile("images/audiomenu.png");

	/** Setup clickable regions **/

	// Controls item coordinates
	MenuItem controlsButton;
	controlsButton.mRect.top = 136;
	controlsButton.mRect.height = 36;
	controlsButton.mRect.left = 235;
	controlsButton.mRect.width = 112;
	controlsButton.action = CONTROLS;

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
	mMenuItems.push_back(controlsButton);
	mMenuItems.push_back(rulesButton);
	mMenuItems.push_back(backButton);

		// Display the texture to the screen.
	mMenuScreen.setTexture(mMenuT);
	window.draw(mMenuScreen);
	window.display();

	return GetMenuResponse(window);
}