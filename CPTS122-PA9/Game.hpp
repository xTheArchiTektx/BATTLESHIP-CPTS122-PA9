/***********************************************\
|												|
|												|
|												|
|												|
\***********************************************/

#ifndef GAME
#define GAME

#include "Menu.hpp"
#include "SplashScreen.hpp"

class Game
{
private:
	// Data Types
	typedef enum gamestate
	{
		UNINITIALIZED, SHOWING_SPLASH, PAUSED, SHOWING_MENU, PLAYING, EXITING
	}GameState;

	// Data Members
	static GameState mGameState;
	static sf::RenderWindow mMainWindow;

	// Member Functions
	static bool isExiting(void);
	static void gameLoop(void);

	static void showSplashScreen(void);
	static void showMenu(void);

public:
	// Member Functons
	static void start(void);

};

#endif // !GAME