#include "Audio.hpp"

//Options::OptionsResult Options::show(sf::RenderWindow& window)
Menu::MenuResult Audio::show(sf::RenderWindow& window)
{
	// Load and texture from file.
	mMenuT.loadFromFile("images/options.png");

	/** Setup clickable regions **/



	// Display the texture to the screen.
	mMenuScreen.setTexture(mMenuT);
	window.draw(mMenuScreen);
	window.display();

	return GetMenuResponse(window);
}