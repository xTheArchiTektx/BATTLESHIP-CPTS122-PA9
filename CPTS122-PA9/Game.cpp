#include "Game.hpp"

using sf::Color;
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
	int shipCount = 0, player = 1;
	Ship::direction shipd = Ship::RIGHT;

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

	case CONTROLS:
		showControls();
		break;

	case PLAYER1_BOARD:
	{
		sf::Event currentEvent;
		while (mMainWindow.pollEvent(currentEvent))
		{
			if (mPlayers == 1)
			{
				if (shipCount < 5)
				{
					// Place Ships
					
					gameBoard_p1.show(true, mMainWindow);
					mMainWindow.display();

					if (currentEvent.type == sf::Event::TextEntered && currentEvent.text.unicode < 128)
					{
						string input;
						input += static_cast<char>(currentEvent.text.unicode);
						
						if (input[0] == 'r')
						{
							if (shipd == Ship::RIGHT)
								shipd = Ship::UP;
							else
								shipd = Ship::RIGHT;
						}
						else if (std::isdigit((int)input[0]))
						{
							gameBoard_p1.setText(input, 1);
							gameBoard_p1.setTextPos(sf::Vector2f(440, 50), 1);
							gameBoard_p1.show(true, mMainWindow);
							mMainWindow.display();
						}
						else
						{
							gameBoard_p1.setText(input, 2);
							gameBoard_p1.setTextPos(sf::Vector2f(490, 50), 2);
							gameBoard_p1.show(true, mMainWindow);
							mMainWindow.display();
						}
					}

					if (currentEvent.type == sf::Event::KeyPressed && currentEvent.KeyPressed == sf::Keyboard::Enter)
					{
						shipCount++;
						mGameState = SHIP_MENU;
					}
				}
				else
				{
					// Initialize ships.
					Ship aircraftCarrier(5, 0, 28, 140, "Carrier", Color::Red);
					Ship battleship(4, 0, 28, 112, "BattleShip", Color::Red);
					Ship patrolBoat(2, 0, 28, 56, "Patrol Boat", Color::Red);
					Ship submarine(3, 0, 28, 84, "Submarine", Color::Red);
					Ship destroyer(3, 0, 28, 84, "Destroyer", Color::Red);
					std::list<Ship> ships;

					ships.push_back(aircraftCarrier);
					ships.push_back(battleship);
					ships.push_back(destroyer);
					ships.push_back(submarine);
					ships.push_back(patrolBoat);
				}

			if (currentEvent.type == sf::Event::MouseButtonPressed)
			{

			}
			else if (currentEvent.type == sf::Event::Closed)
			{
				mGameState = EXITING;
			}
			}
			else if (mPlayers == 2)
			{
				
			}
		}

		break;

		case PLAYER2_BOARD:
			break;

		case SHIP_MENU:
			showShipsMenu(shipCount, player);
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

		// INITIALIZATION
	gameBoard_p1.loadDefault();

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
	Menu::MenuResult result = mainMenu.show(mMainWindow, mPlayers);

	// Set the game state.
	switch (result)
	{
	case Menu::EXIT:
		mGameState = EXITING;
		break;

	case Menu::PLAY:
		mGameState = SHIP_MENU;
		break;

	case Menu::OPTION:
		mGameState = OPTION;

	case Menu::CREDIT:
		mGameState = OPTION;
	}
}

void Game::showOptions(void)
{
	Options optionsMenu;
	Menu::MenuResult result = optionsMenu.show(mMainWindow);

	// Set the game state.
	switch (result)
	{
	case Menu::MenuResult::BACK:
		mGameState = SHOWING_MENU;
		break;

	case Menu::MenuResult::RULES:
		mGameState = RULES;
		break;

	case Menu::MenuResult::CONTROLS:
		mGameState = CONTROLS;
		break;
		
	case Menu::MenuResult::AUDIO:
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
	Rules rulesMenu;
	Menu::MenuResult result = rulesMenu.show(mMainWindow);

	// Set the game state.
	switch (result)
	{
	case Menu::MenuResult::BACK:
		mGameState = SHOWING_MENU;
		break;

	case Menu::MenuResult::CONTROLS:
		mGameState = CONTROLS;
		break;

	case Menu::MenuResult::AUDIO:
		mGameState = AUDIO;
		break;
	}
}

void Game::showAudio(void)
{
	Audio audioMenu;
	Menu::MenuResult result = audioMenu.show(mMainWindow);

	// Set the game state.
	switch (result)
	{
	case Menu::MenuResult::BACK:
		mGameState = SHOWING_MENU;
		break;

	case Menu::MenuResult::CONTROLS:
		mGameState = CONTROLS;
		break;

	case Menu::MenuResult::RULES:
		mGameState = RULES;
		break;
	}
}

void Game::showControls(void)
{
	Controls controlsMenu;
	Menu::MenuResult result = controlsMenu.show(mMainWindow);

	// Set the game state.
	switch (result)
	{
	case Menu::MenuResult::BACK:
		mGameState = SHOWING_MENU;
		break;

	case Menu::MenuResult::RULES:
		mGameState = RULES;
		break;

	case Menu::MenuResult::AUDIO:
		mGameState = AUDIO;
		break;
	}
}

Texture Game::showShipsMenu(int shipCount, int player)
{
	ShipsMenu shipSelection;
	Menu::MenuResult result = Menu::NOTHING;
	Menu::MenuResult ship = Menu::NOTHING;

	result = shipSelection.show(mMainWindow);

	switch (result)
	{
		case Menu::CARRIER:
			mShipT.loadFromFile("images/AircraftCarrier.png");
			break;

		case Menu::BATTLESHIP:
			mShipT.loadFromFile("images/Battleship.png");
			break;

		case Menu::DESTROYER:
			mShipT.loadFromFile("images/Destroyer.png");
			break;

		case Menu::SUB:
			mShipT.loadFromFile("images/Submarine.png");
			break;

		case Menu::PATROL_BOAT:
			mShipT.loadFromFile("images/PatrolBoat.png");
			break;
	}

	mGameState = PLAYER1_BOARD;
	//return shipT;
}

// Static Variables
Game::GameState Game::mGameState = UNINITIALIZED;
sf::RenderWindow Game::mMainWindow;
int Game::mPlayers = 1;
Texture Game::mShipT;
GameBoard Game::gameBoard_p1;
GameBoard Game::gameBoard_cpu;