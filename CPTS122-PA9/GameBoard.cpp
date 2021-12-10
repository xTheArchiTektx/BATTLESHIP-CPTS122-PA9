#include "GameBoard.hpp"

void GameBoard::setFont(std::string font)
{
	mScreenFont.loadFromFile(font);
}
void GameBoard::setTexture(std::string texture)
{
	mScreenImage.loadFromFile(texture);
}
void GameBoard::setMusic(std::string music)
{
	mAudio.openFromFile(music);
}

void GameBoard::setText(std::string str, int num)
{
	if (num == 1)
	{
		screenText.setString(str);
	}
	else
	{
		t2.setString(str);
	}
}

void GameBoard::setTextPos(sf::Vector2f vec, int num)
{
	if (num == 1)
	{
		screenText.setPosition(vec);
	}
	else
	{
		t2.setPosition(vec);
	}
}

LinkedList<Sprite>GameBoard::getList(void)
{
	return shotList;
}
BoardGrid GameBoard::getGrid(void)
{
	return mapGrid;
}

void GameBoard::show(bool isSound, RenderWindow& appWindow)
{
	appWindow.draw(mScreenBack);
	appWindow.draw(screenText);
	appWindow.draw(t2);
	this->drawMarkers(appWindow);
}

void GameBoard::loadDefault(void) //loads the default game screen music text
{
	if (mScreenFont.loadFromFile("fonts/BlackOpsOne-Regular.ttf"))
	{
		screenText.setFont(mScreenFont);
		screenText.setFillColor(sf::Color::White);
		screenText.setCharacterSize(20);
		t2.setFont(mScreenFont);
		t2.setFillColor(sf::Color::White);
		t2.setCharacterSize(20);
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
	int xLoc = ZWApixLocationX + 28 * (xCord - 1);
	int yLoc = ZWApixLocationY + 28 * (yCord - 1);
	if (checkGrid(xCord, yCord) == Grid::EMPTY)//shot was a miss
	{
		Texture missMarker;
		Sprite missImage;
		missMarker.loadFromFile("images/Miss.png");
		missImage.setTexture(missMarker);
		missImage.setPosition(sf::Vector2f(xLoc, yLoc));
		Grid bGrid = mapGrid.getTargetGrid(xCord, yCord);
		bGrid.setCondition(Grid::MISS);
		shotList.insert((shotList.getHead()->makeNode(missImage)));
	}
	else if (checkGrid(xCord, yCord) == Grid::OCCUPIED)
	{
		Texture hitMarker;
		Sprite hitImage;
		hitMarker.loadFromFile("images/Hit.png");
		hitImage.setTexture(hitMarker);
		hitImage.setPosition(sf::Vector2f(xLoc, yLoc));
		Grid bGrid = mapGrid.getTargetGrid(xCord, yCord);
		bGrid.setCondition(Grid::HIT);
		shotList.insert(shotList.getHead()->makeNode(hitImage));
	}
	else
	{

	}

}

Grid::GridCondition GameBoard::checkGrid(int xCord, int yCord)//Checks the grid inputed and returns the grids current condition
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

LinkedList<Ship>GameBoard::getSList(void)
{
	return shipList;
}

void GameBoard::insertShip(Ship newShip)
{
	ListNode<Ship>* newNode = new ListNode<Ship>(newShip);
	
}
void GameBoard::putShipOnGrid(Ship newShip, int StartX, int StartY,Ship::direction placementDir)
{
	switch (placementDir)
	{
	case Ship::UP:
		for (int i = 0; i < newShip.getGridLength(); i++)
		{
			Grid temp = this->mapGrid.getTargetGrid(StartX, StartY+i);
			temp.setCondition(Grid::OCCUPIED);
		}
		break;
	case Ship::RIGHT:
		for (int i = 0; i < newShip.getGridLength(); i++)
		{
			Grid temp = this->mapGrid.getTargetGrid(StartX+i, StartY);
			temp.setCondition(Grid::OCCUPIED);
		}
		break;
	}
}
int GameBoard::ZWApixLocationX = 96;
int GameBoard::ZWApixLocationY = 107;