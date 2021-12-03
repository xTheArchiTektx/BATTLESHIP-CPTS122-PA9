#include "Controls.hpp"

//controls::controlsResult controls::show(sf::RenderWindow& window)
Menu::MenuResult Controls::show(sf::RenderWindow& window)
{
	// Load and texture from file.
	mMenuT.loadFromFile("images/controls.png");

	/** Setup clickable regions **/



	// Display the texture to the screen.
	mMenuScreen.setTexture(mMenuT);
	window.draw(mMenuScreen);
	window.display();

	return GetMenuResponse(window);
}