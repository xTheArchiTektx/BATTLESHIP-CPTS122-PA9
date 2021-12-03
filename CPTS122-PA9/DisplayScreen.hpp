#ifndef DISPLAY_SCREEN
#define DISPLAY_SCREEN

#include "PA9.hpp"

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
		// Constructors
	DisplayScreen(void);

		// Setters
	void setFont(string font);
	void setTexture(string texture);
	void setMusic(string music);

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
	virtual void show(Text screenText, bool isSound, RenderWindow& window);

protected:
	Font mScreenFont;
	Texture mSpiteTexture;
	Sprite mScreenBack;
	Music mAudio;
	//RenderWindow mDisplayScreen; //used to store the application window (RenderWindow displayScreen)
};

#endif // !DISPLAY_SCREEN