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
	void show(bool isSound, RenderWindow& window);

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
	bool loadGraphics(void);
private:
	/** Inherits displayScreen; (RenderWindow, Spriteand Audio) **/
	Text mScreenText;
};

#endif // !SPLASH_SCREEN
