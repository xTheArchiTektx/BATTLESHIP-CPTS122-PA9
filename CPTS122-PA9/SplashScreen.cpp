
#include "SplashScreen.hpp"

/***********************************************\
	Function Name: show()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: (sf::RenderWindow& window)
	Returns: NONE
	Pre-Conditions: NONE
	Description: This function displays the
		splash screen to the window until input
		from the user is detected.
\***********************************************/
void SplashScreen::show(sf::RenderWindow& window)
{
	// Create a texture.
	sf::Texture texture;
	if (texture.loadFromFile("images/SplashScreen.png") != true) // error checking
	{
		return;
	}

	// Display a sprite to the screen
	sf::Sprite sprite(texture);
	window.draw(sprite);

	// Load the font
	sf::Font font;
	if (!font.loadFromFile("fonts/BlackOpsOne-Regular.ttf"))
	{
		std::cout << "Error loading font!" << std::endl;
	}

	// Load the text
	sf::Text continueText;
	continueText.setFont(font);
	continueText.setFillColor(sf::Color::White);
	continueText.setCharacterSize(20);
	continueText.setString("Press any key to continue...");
	continueText.setPosition(sf::Vector2f(200, 450));

	window.draw(continueText);
	window.display();

		// Load the soundtrack.
	sf::Music soundTrack;
	soundTrack.openFromFile("soundtrack/SplashScreen.ogg");
	soundTrack.setVolume(15.0f);
	soundTrack.setLoop(true);
	soundTrack.play();

	// Get a action from the user to end.
	sf::Event event;
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed)
			{
				soundTrack.stop();
				return;
			}
		}
	}
}