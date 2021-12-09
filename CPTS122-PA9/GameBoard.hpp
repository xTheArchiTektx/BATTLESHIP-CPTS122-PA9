#pragma once
#include "PA9.hpp"
#include "mapGrid.hpp"
#include "LinkedList.hpp"
	const int pixLocationX = 96;
	const int pixLocationY = 107;

class GameBoard
{
public:
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
	Grid::gridCondition checkGrid(int xCord, int yCord); //Checks the grid inputed and returns the grids current condition
	void drawMarkers(RenderWindow& appWindow);

protected:

private:
	Font mScreenFont;
	Texture mScreenImage;
	Sprite mScreenBack;
	Music mAudio;
	//std::list<Sprite> shotList;
	LinkedList<Sprite> shotList; //used to store the sprites being used to mark the grid
	BoardGrid mapGrid;
	Text screenText;
	//RenderWindow& applicationWin;//must be set in constructor
};