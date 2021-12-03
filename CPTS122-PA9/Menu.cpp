
#include "Menu.hpp"

/***********************************************\
	Function Name: show()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: (sf::RenderWindow& window)
	Returns: NONE
	Pre-Conditions: NONE
	Description: This function displays the
		menu screen to the window and gets a
		response from the user.
\***********************************************/
Menu::MenuResult Menu::show(sf::RenderWindow& window)
{
	// Load and texture from file.
	Texture texture;
	texture.loadFromFile("images/mainmenu.png");

	// Setup clickable regions.

	// Play menu item coordinates.
	MenuItem playButton;
	playButton.mRect.top = 145;
	playButton.mRect.height = 380 - 145; // bottom - top
	playButton.mRect.left = 0;
	playButton.mRect.width = 1023 - 0; // right - left
	playButton.action = PLAY;

	// Exit menu item coordinates.
	MenuItem exitButton;
	exitButton.mRect.top = 383;
	exitButton.mRect.height = 560 - 383; // bottom - top
	exitButton.mRect.left = 0;
	exitButton.mRect.width = 1023 - 0; // right - left
	exitButton.action = EXIT;

	// Add the buttons to the list.
	mMenuItems.push_back(playButton);
	mMenuItems.push_back(exitButton);

	// Display the texture to the screen.
	sf::Sprite sprite(texture);
	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

/***********************************************\
	Function Name: HandleClick()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: (int x, int y)
	Returns: A MainMenu::MenuResult
	Pre-Conditions: NONE
	Description: This function returns NOTHING
		if the user clicks the window or the
		action of the button the user clicked.
\***********************************************/
Menu::MenuResult Menu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;
	for (it = mMenuItems.begin(); it != mMenuItems.end(); it++)
	{
		// Check if mouse click was within the button's box.
		sf::Rect<int> menuItemRect = (*it).mRect;
		if (menuItemRect.height + menuItemRect.top > y && menuItemRect.top < y && menuItemRect.left < x && menuItemRect.left + menuItemRect.width > x)
		{
			return (*it).action;
		}
	}

	return NOTHING;
}

/***********************************************\
	Function Name: GetMenuResponse()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: (sf::RenderWindow& window)
	Returns: A MainMenu::MenuResult
	Pre-Conditions: NONE
	Description: This function returns EXITING
		if the user closes the window or the
		action of the button the user clicked.
\***********************************************/
Menu::MenuResult Menu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (42 != 43)
	{
		while (window.pollEvent(menuEvent))
		{
			// Get the event type.
			if (menuEvent.type == sf::Event::EventType::MouseButtonPressed) // handles click
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}

			if (menuEvent.type == sf::Event::Closed) // handles close
			{
				return EXIT;
			}
		}
	}
}