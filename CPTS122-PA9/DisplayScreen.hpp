#pragma once
#include "PA9.hpp"
using sf::RenderWindow;
using sf::Sprite;
using sf::Texture;
using sf::Font;
using sf::Text;
using sf::Music;

/**********************************************************************************************************************************************
* Class: DisplayScreen
* Created by: Zachary Garoutte
* Date Created: 12/2/2021
* Last Modified: 12/2/2021
* Inhertince: None
* Public namespace:
*		show(); See function Declaration
* 
* Protected namespace:
*		RenderWindow& displayScreen;
* 
* Private namespace:
*		None
* 
* Description: Base class for a Display screen object
* 
**********************************************************************************************************************************************/

class DisplayScreen
{
public:

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
	virtual void show(Sprite screenGraphics, Text screenText, bool isSound, Music displayAudio)
	{
		displayScreen.draw(screenGraphics);
		displayScreen.draw(screenText);
		if (isSound)
		{
			displayAudio.play();
		}
	}
protected:
	sf::RenderWindow &displayScreen; //used to store the application window (RenderWindow displayScreen)
private:

};