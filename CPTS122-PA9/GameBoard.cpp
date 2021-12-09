#include "GameBoard.hpp"

void GameBoard::setFont(string font)
{
	mScreenFont.loadFromFile(font);
}
void GameBoard::setTexture(string texture)
{
	mScreenImage.loadFromFile(texture);
}
void GameBoard::setMusic(string music)
{
	mAudio.openFromFile(music);
}

LinkedList<Sprite>GameBoard::getList(void)
{
	return shotList;
}
BoardGrid GameBoard::getGrid(void)
{
	return this->mapGrid;
}

void GameBoard::show(bool isSound, RenderWindow& appWindow)
{
	appWindow.draw(mScreenBack);
	appWindow.draw(screenText);

}

void GameBoard::loadDefault(void) //loads the default game screen music text
{
	if (mScreenFont.loadFromFile("fonts/BlackOpsOne-Regular.ttf"))
	{
		screenText.setFont(mScreenFont);
		screenText.setFillColor(sf::Color::White);
		screenText.setCharacterSize(20);
	}
	if (mScreenImage.loadFromFile("images/GameBoard.png"))
	{
		mScreenBack.setTexture(mScreenImage);
	}
	if (mAudio.openFromFile("soundtrack/SplashScreen.ogg"))
	{
		mAudio.setVolume(15.f);
		mAudio.setLoop(true);
	}
}

bool GameBoard::updateGrid(int xCord, int yCord)//puts x for hit or miss on screen
{
	int xLoc = pixLocationX + 28 * (xCord - 1);
	int yLoc = pixLocationY + 28 * (yCord - 1);
	if (checkGrid(xCord, yCord) == Grid::EMPTY)//shot was a miss
	{
		Texture missMarker;
		Sprite missImage;
		missMarker.loadFromFile("images/Miss.png");
		missImage.setTexture(missMarker);
		missImage.setPosition(sf::Vector2f(xLoc, yLoc));
		Grid& bGrid = mapGrid.getTargetGrid(xCord, yCord);
		bGrid.setCondition(Grid::MISS);
		shotList.insert(shotList.getHead()->makeNode(missImage));
	}
	else if (checkGrid(xCord, yCord) == Grid::OCCUPIED)
	{
		Texture hitMarker;
		Sprite hitImage;
		hitMarker.loadFromFile("images/Hit.png");
		hitImage.setTexture(hitMarker);
		hitImage.setPosition(sf::Vector2f(xLoc, yLoc));
		Grid& bGrid = mapGrid.getTargetGrid(xCord, yCord);
		bGrid.setCondition(Grid::HIT);
		shotList.insert(shotList.getHead()->makeNode(hitImage));
	}
	else
	{

	}

}

Grid::gridCondition GameBoard::checkGrid(int xCord, int yCord)//Checks the grid inputed and returns the grids current condition
{
	return this->mapGrid.getTargetGrid(xCord, yCord).getCurrentCond();
}

void GameBoard::drawMarkers(RenderWindow& appWindow)
{
	ListNode<Sprite>* temp = shotList.getHead();
	while (temp != nullptr)
	{
		appWindow.draw(temp->getData());
		temp = temp->getNext();
	}
}

void GameBoard::insertSprite(Sprite newSprite)
{
	ListNode<Sprite>* newNode = this->shotList.getHead()->makeNode(newSprite);
	shotList.insert(newNode);
}