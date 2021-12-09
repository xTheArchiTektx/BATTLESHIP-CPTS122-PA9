#pragma once
#include "PA9.hpp"
#include "SplashScreen.hpp"
#include "mapGrid.hpp"

class GameBoardDisplay : public SplashScreen
{
public:
	//inherits show()
	virtual bool loadGraphics(void);
	Grid getGrid(void);

protected:
	//None
private:
	//Inherits displayScreen
	//Inherits displayText
	Grid mapGrid;

};
