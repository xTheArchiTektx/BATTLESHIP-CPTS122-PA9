#pragma once

#include "GameBoardDisplay.hpp"
#include "LinkedList.hpp"
#include "boardGrid.hpp"

class GameBoard
{
public:
//	static int ZWApixLocationX;
//	static int ZWApixLocationY;

	//Constructor and Destructor
	GameBoard(void) {};
	~GameBoard(void) {};

	//setters
	void setFont(string font);
	void setTexture(string texture);
	void setMusic(string music);
	

	//getters
	LinkedList<Sprite>getList(void);
	BoardGrid getGrid(void);

	//Member Functions
	void show(bool isSound, RenderWindow& appWindow);
	void loadDefault(void); //loads the default game screen music text
	bool updateGrid(int xCord, int yCord);//puts x for hit or miss on screen
	Grid::GridCondition checkGrid(int xCord, int yCord); //Checks the grid inputed and returns the grids current condition
	void drawMarkers(RenderWindow& appWindow);
	void insertSprite(Sprite newSprite);
protected:

private:
	Font mScreenFont;
	Texture mScreenImage;
	Sprite mScreenBack;
	Music mAudio;
	//std::list<Sprite> shotList;
	LinkedList<Sprite> shotList; //used to store the sprites being used to mark the grids (also contains the ship sprites)
	BoardGrid mapGrid;
	Text screenText;
	//RenderWindow& applicationWin;//must be set in constructor
};