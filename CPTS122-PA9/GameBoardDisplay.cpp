#include "GameBoardDisplay.hpp"

bool GameBoardDisplay::loadGraphics(void)
{
	bool success = true;

	if (!mSpiteTexture.loadFromFile("images/GameBoard.png"))
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
}