/*******************************************************************************\
|	Class: SplashScreen															|
|	Created by: Nicholas Bellinger, and Zach Garoutte							|
|	Studio: N/A																	|
|	Date Created: 11/20/2021													|
|	Date Last Modified: 12/2/2021												|
|	Inhertiance: Public DisplayScreen											|
|	Public: Inherted show() function (See declaration in DisplayScreen.hpp);	|
|			LoadSplashS() (See declaration below)								|
|	Protected: Inherted RenderWindow; Sprite screenBack; Music audio;			|
|				Text Screen Text												|
|	Private: None																|
|	Description: This is the SplashScreen class. It contains the				|
|		inherited member funciton show which displays the splash screen.		|
\*******************************************************************************/

#ifndef SPLASH_SCREEN
#define SPLASH_SCREEN

#include "DisplayScreen.hpp"

class SplashScreen : public DisplayScreen
{
public:
	SplashScreen() : DisplayScreen() {}
	/** Inherits show(); **/

/**********************************************************************************************************************************************
* Function: show()
* Created by: Zachary Garoutte
* Date Created: 12/2/2021
* Last Modified: 12/2/2021
* Input Parameters: screenGraphics, screenText, isSound, displayAudio
* Outputs: Void
* PreConditions: Sprite for Screen graphics loaded, text loaded, and sound track loaded
* PostConditions: Gamescreen Displayed
* Description: Displays the inputed graphic properties to the Application Render Window
**********************************************************************************************************************************************/
	void show(bool isSound, RenderWindow& window)
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

/**********************************************************************************************************************************************
* Function: LoadGraphics()
* Created by: Zachary Garoutte and Nicholas Bellinger
* Date Created: 12/2/2021
* Last Modified: 12/2/2021
* Input Parameters: None
* Outputs: True or False if graphics loaded correctly
* PreConditions: None
* PostConditions: Updated Protected data members
* Description: Loads the graphics for the display screen from the resource files
**********************************************************************************************************************************************/
	bool loadGraphics(void)
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
private:
	/** Inherits displayScreen; (RenderWindow, Spriteand Audio) **/
	Text mScreenText;
};

#endif // !SPLASH_SCREEN
