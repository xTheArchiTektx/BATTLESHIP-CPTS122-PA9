
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
Menu::MenuResult Menu::show(sf::RenderWindow& window, int& playerCount)
{
		// Load and texture from file.
	mMenuT.loadFromFile("images/mainmenu.png");

	/** Setup clickable regions **/

		// Play menu item coordinates.
	MenuItem playButton;
	playButton.mRect.top = 160;
	playButton.mRect.height = 60; // bottom - top
	playButton.mRect.left = 275;
	playButton.mRect.width = 225; // right - left
	playButton.action = PLAY;

		// Option menu item coordinates.
	MenuItem optionsButton;
	optionsButton.mRect.top = 240;
	optionsButton.mRect.height = 60; // bottom - top
	optionsButton.mRect.left = 275;
	optionsButton.mRect.width = 225; // right - left
	optionsButton.action = OPTION;

		// Credits menu item coordinates.
	MenuItem creditsButton;
	creditsButton.mRect.top = 320;
	creditsButton.mRect.height = 60; // bottom - top
	creditsButton.mRect.left = 275;
	creditsButton.mRect.width = 225; // right - left
	creditsButton.action = CREDIT;

		// Exit menu item coordinates.
	MenuItem exitButton;
	exitButton.mRect.top = 400;
	exitButton.mRect.height = 60; // bottom - top
	exitButton.mRect.left = 275;
	exitButton.mRect.width = 225; // right - left
	exitButton.action = EXIT;

		// Add the buttons to the list.
	mMenuItems.push_back(playButton);
	mMenuItems.push_back(optionsButton);
	mMenuItems.push_back(creditsButton);
	mMenuItems.push_back(exitButton);

		// Display the texture to the screen.
	mMenuScreen.setTexture(mMenuT);
	window.draw(mMenuScreen);
	window.display();

	MenuResult result = GetMenuResponse(window);

	if (result == PLAY)
	{
		loadPlayerButtons(window);

		MenuItem p1Button;
		p1Button.mRect.top = 190;
		p1Button.mRect.height = 60; // bottom - top
		p1Button.mRect.left = 25;
		p1Button.mRect.width = 225; // right - left
		p1Button.action = PLAYER_1;

		MenuItem p2Button;
		p2Button.mRect.top = 270;
		p2Button.mRect.height = 60; // bottom - top
		p2Button.mRect.left = 25;
		p2Button.mRect.width = 225; // right - left
		p2Button.action = PLAYER_2;

		mMenuItems.clear();
		mMenuItems.push_back(p1Button);
		mMenuItems.push_back(p2Button);

		MenuResult player = NOTHING;
		while (player == NOTHING)
		{
			player = GetMenuResponse(window);

			if (player == PLAYER_1)
			{
				playerCount = 1;
			}
			else if (player == PLAYER_2)
			{
				playerCount = 2;
			}
		}
	}

	return result;
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
			else if (menuEvent.type == sf::Event::EventType::Resized)
			{
					// Display the texture to the screen.
				window.draw(mMenuScreen);
				window.display();
			}

			if (menuEvent.type == sf::Event::Closed) // handles close
			{
				return EXIT;
			}
		}
	}
}

void Menu::loadPlayerButtons(RenderWindow& window)
{
	Texture t1, t2;

	t1.loadFromFile("images/1-Player.png");
	t2.loadFromFile("images/2-Player.png");

	Sprite b1(t1), b2(t2);

	b1.setPosition(sf::Vector2f(25, 190));
	b2.setPosition(sf::Vector2f(25, 270));

	window.draw(mMenuScreen);
	window.draw(b1);
	window.draw(b2);

	window.display();
}