#include "Game.hpp"
#include "GameBoardDisplay.hpp"
/***********************************************\
	Function Name: isExiting()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: NONE
	Returns: A bool
	Pre-Conditions: NONE
	Description: This function will return true
		if the current state of the game is
		exiting and false if otherwise.
\***********************************************/
bool Game::isExiting(void)
{
	if (mGameState == EXITING)
		return true;
	else
		return false;
}

/***********************************************\
	Function Name: gameLoop()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: NONE
	Returns: NONE
	Pre-Conditions: NONE
	Description: This function runs the
		gameloop. It handles the event queue
		for the program.
\***********************************************/
void Game::gameLoop(void)
{
	switch (mGameState)
	{
	case SHOWING_SPLASH:
		showSplashScreen();
		break;

	case SHOWING_MENU:
		showMenu();
		break;

	case OPTION:
		showOptions();
		break;

	case CREDIT:
		showCredits();
		break;

	case RULES:
		showRules();
		break;

	case AUDIO:
		showAudio();
		break;

	case VIDEO:
		showVideo();
		break;

	case CONTROLS:
		showControls();
		break;

	case PLAYING:
	{
		sf::Event currentEvent;
		while (mMainWindow.pollEvent(currentEvent))
		{
			mMainWindow.clear(sf::Color(255, 0, 0));
			mMainWindow.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				mGameState = EXITING;
			}
			else if (currentEvent.type == sf::Event::Resized)
			{

			}
		GameBoardDisplay gameBoard;
		bool success = gameBoard.loadGraphics();
		gameBoard.show(false, mMainWindow);

		}

		break;
	}
	}
}

/***********************************************\
	Function Name: start()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: NONE
	Returns: NONE
	Pre-Conditions: NONE
	Description: This function creates the game
		window, runs the game, and then closes
		the window.
\***********************************************/
void Game::start(void)
{
	if (mGameState != UNINITIALIZED) // error checking
		return;

	// Create a window.
	mMainWindow.create(sf::VideoMode(560, 560), "BATTLESHIP!");
	mGameState = SHOWING_SPLASH;

	// Run the gameloop.
	while (!isExiting())
	{
		gameLoop();
	}

	// Close the window.
	mMainWindow.close();
}

/***********************************************\
	Function Name: showSplashScreen()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: NONE
	Returns: NONE
	Pre-Conditions: NONE
	Description: This function displays the
	splash screen and changes the gamestate.
\***********************************************/
void Game::showSplashScreen(void)
{
	SplashScreen splashScreen;
	splashScreen.loadGraphics();
	splashScreen.show(true, mMainWindow);
	mGameState = SHOWING_MENU;
}

/***********************************************\
	Function Name: showMenu()
	Date Created: 11/20/2021
	Date Last Modified: 11/20/2021
	Input Parameters: NONE
	Returns: NONE
	Pre-Conditions: NONE
	Description: This function displays the menu
		to the screen and changes the gamestate
		depending on what the user does in the
		menu.
\***********************************************/
void Game::showMenu(void)
{
	// Display the menu.
	Menu mainMenu;
	Menu::MenuResult result = mainMenu.show(mMainWindow);

	// Set the game state.
	switch (result)
	{
	case Menu::EXIT:
		mGameState = EXITING;
		break;

	case Menu::PLAY:
		mGameState = PLAYING;
		break;

	case Menu::OPTION:
		mGameState = OPTION;

	case Menu::CREDIT:
		mGameState = CREDIT;
	}
}

void Game::showOptions(void)
{
	Options optionsMenu;
	Menu::MenuResult result = optionsMenu.show(mMainWindow);
	//Options::optionsresult result = optionsMenu.show(mMainWindow);


	// Set the game state.
	switch (result)
	{
	case Options::optionsresult::BACK:
		mGameState = SHOWING_MENU;
		break;

	case Options::optionsresult::RULES:
		mGameState = RULES;
		break;

	case Options::optionsresult::CONTROLS:
		mGameState = CONTROLS;
		break;

	case Options::optionsresult::VIDEO:
		mGameState = VIDEO;
		break;
		
	case Options::optionsresult::AUDIO:
		mGameState = AUDIO;
		break;
	}
}

void Game::showCredits(void)
{
	DisplayScreen credits;
	Text text;
	Font font;
	font.loadFromFile("fonts/BlackOpsOne-Regular.ttf");
	text.setFont(font);
	text.setString("Click any button to continue");
	credits.setFont("fonts/BlackOpsOne-Regular.ttf");
	credits.setTexture("images/credits");
	credits.show(text, false, mMainWindow);

	mGameState = SHOWING_MENU;
}

void Game::showRules(void)
{
	DisplayScreen rules;
	Text text;
	Font font;
	font.loadFromFile("fonts/BlackOpsOne-Regular.ttf");
	text.setFont(font);
	text.setString("Click any button to continue");
	rules.setFont("fonts/BlackOpsOne-Regular.ttf");
	rules.setTexture("images/rules");
	rules.show(text, false, mMainWindow);

	mGameState = SHOWING_MENU;
}

void Game::showAudio(void)
{
	Audio audioMenu;
	Menu::MenuResult result = audioMenu.show(mMainWindow);
	//Audio::AudioResult result = audioMenu.show(mMainWindow);

	switch (result)
	{
	case Audio::AudioResult::BACK:
		mGameState = SHOWING_MENU;
		break;
	}
}

void Game::showVideo(void)
{
	Video videoMenu;
	Menu::MenuResult result = videoMenu.show(mMainWindow);
	//Video::VideoResult result = videoMenu.show(mMainWindow);

	switch (result)
	{
	case Video::VideoResult::BACK:
		mGameState = SHOWING_MENU;
		break;
	}
}

void Game::showControls(void)
{
	Controls controlsMenu;
	Menu::MenuResult result = controlsMenu.show(mMainWindow);
	//Controls::ControlsResult result = controlsMenu.show(mMainWindow);

	switch (result)
	{
	case Controls::ControlsResult::BACK:
		mGameState = SHOWING_MENU;
		break;
	}
}

// Static Variables
Game::GameState Game::mGameState = UNINITIALIZED;
sf::RenderWindow Game::mMainWindow;