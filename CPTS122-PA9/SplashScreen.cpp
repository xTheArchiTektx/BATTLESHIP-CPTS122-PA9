
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
void SplashScreen::show(bool isSound, RenderWindow& window)
	{
	window.draw(this->mScreenBack);
	window.draw(this->mScreenText);
	window.display();

	if (isSound)
	{
		this->mAudio.play();
	}

	sf::Event event;
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed)
			{
				this->mAudio.stop();
				return;
			}
		}
	}
	}

bool SplashScreen::loadGraphics(void)
{
	bool success = true;

	if (!mSpiteTexture.loadFromFile("images/SplashScreen.png"))
	{
		success = false;
	}
	else
	{
		mScreenBack.setTexture(mSpiteTexture);
	}

	if (!mScreenFont.loadFromFile("fonts/BlackOpsOne-Regular.ttf"))
	{
		success = false;
	}
	else
	{
		//Font successful Load text next:
		mScreenText.setFont(mScreenFont);
		mScreenText.setFillColor(sf::Color::White);
		mScreenText.setCharacterSize(20);
		mScreenText.setString("Press Any Key to Continue...");
		mScreenText.setPosition(sf::Vector2f(200, 450));
	}

	if (!mAudio.openFromFile("soundtrack/SplashScreen.ogg"))
	{
		success = false;
	}
	else
	{
		mAudio.setVolume(15.f);
		mAudio.setLoop(true);
	}

	return success;
}