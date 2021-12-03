/*******************************************************************************\
|	Class: SplashScreen
	Created by: Nicholas Bellinger, and Zach Garoutte							|
|	Studio: N/A																	|
|	Date Created: 11/20/2021													|
|	Date Last Modified: 12/2/2021												|
|	Inhertiance: Public DisplayScreen
|	Public: Inherted show() function (See declaration in DisplayScreen.hpp);
|			LoadSplashS() (See declaration below)
|	Protected: Inherted RenderWindow; Sprite screenBack; Music audio;
|				Text Screen Text
|	Private: None
|	Description: This is the SplashScreen class. It contains the				|
|		inherited member funciton show which displays the splash screen.		|
\*******************************************************************************/

#ifndef SPLASH_SCREEN
#define SPLASH_SCREEN

#include "DisplayScreen.hpp"
using sf::Sprite;
using sf::Music;
using sf::Font;
using sf::Text;

class SplashScreen : public DisplayScreen
{
public:
	SplashScreen();
	//Inherits show();

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
	virtual void show(bool isSound)
	{
		displayScreen.draw(this->screenBack);
		displayScreen.draw(this->screenText);
		if (isSound)
		{
			this->audio.play();
		}
		sf::Event event;
		while (true)
		{
			while (displayScreen.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed)
				{
					this->audio.stop();
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
		Texture imageT;
		Font screenFont;
		bool success = false;
		if (!imageT.loadFromFile("images/SplashScreen.png"))
		{
			success = false;
		}
		else
		{
			screenBack.setTexture(imageT);
			success = true;
		}
		if (!screenFont.loadFromFile("fonts/BlackOpsOne-Regular.ttf"))
		{
			success = false;
		}
		else
		{
			//Font successful Load text next:
			screenText.setFont(screenFont);
			screenText.setFillColor(sf::Color::White);
			screenText.setCharacterSize(20);
			screenText.setString("Press Any Key to Continue...");
			screenText.setPosition(sf::Vector2f(200, 450));
			success = true;
		}
		if (!audio.openFromFile("soundtrack/SplashScreen.ogg"))
		{
			success = false;
		}
		else
		{
			audio.setVolume(15.f);
			audio.setLoop(true);
			success = true;
		}
		return success;
	}
protected:
	//Inherits displayScreen;(RenderWindow&)
	Sprite screenBack;
	Music audio;
	Text screenText;
private:
	//None
};

#endif // !SPLASH_SCREEN
