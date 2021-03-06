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
#include "Controls.hpp"
#include "SplashScreen.hpp"
#include "Ship.hpp"
#include "ShipsMenu.hpp"
#include "Rules.hpp"
#include "GameBoard.hpp"

class Game
{
private:
		// Data Types
	typedef enum gamestate
	{
		UNINITIALIZED, SHOWING_SPLASH, PAUSED, SHOWING_MENU, PLAYER1_BOARD, PLAYER2_BOARD, EXITING, CREDIT, OPTION, RULES, AUDIO, CONTROLS, SHIP_MENU
	}GameState;
	typedef enum ycoordinates
	{
		A,B,C,D,E,F,G,H,I,J
	}YCoordinates;
		// Data Members
	static GameState mGameState;
	static sf::RenderWindow mMainWindow;
	static int mPlayers;
	static Texture mShipT; 
	static GameBoard gameBoard_p1;
	static GameBoard gameBoard_cpu;
	static Menu::MenuResult currShip;
	static int xCurr;
	static int yCurr;
		// Setters
	static int setPlayers(void);

		// Member Functions
	static bool isExiting(void);
	static void gameLoop(void);

	static void showSplashScreen(void);
	static void showMenu(void);
	static void showOptions(void);
	static void showCredits(void);
	static void showRules(void);
	static void showAudio(void);
	static void showControls(void);
	static Texture showShipsMenu(int shipCount, int player);
	static int findyCurr(char input);

public:
		// Member Functons
	static void start(void);

};

#endif // !GAME