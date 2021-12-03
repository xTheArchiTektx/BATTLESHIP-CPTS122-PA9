/***********************************************\
|												|
|												|
|												|
|												|
\***********************************************/

#ifndef GAME
#define GAME

#include "Options.hpp"
#include "Audio.hpp"
#include "Video.hpp"
#include "Controls.hpp"
#include "SplashScreen.hpp"

class Game
{
private:
	// Data Types
	typedef enum gamestate
	{
		UNINITIALIZED, SHOWING_SPLASH, PAUSED, SHOWING_MENU, PLAYING, EXITING, CREDIT, OPTION, RULES, AUDIO, VIDEO, CONTROLS
	}GameState;

	// Data Members
	static GameState mGameState;
	static sf::RenderWindow mMainWindow;

	// Member Functions
	static bool isExiting(void);
	static void gameLoop(void);

	static void showSplashScreen(void);
	static void showMenu(void);
	static void showOptions(void);
	static void showCredits(void);
	static void showRules(void);
	static void showAudio(void);
	static void showVideo(void);
	static void showControls(void);

public:
	// Member Functons
	static void start(void);

};

#endif // !GAME