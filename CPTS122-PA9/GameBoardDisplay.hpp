#pragma once
#include "PA9.hpp"
#include "DisplayScreen.hpp"
#include "SplashScreen.hpp"

class GameBoardDisplay : public SplashScreen
{
public:
	//inherits show()
	virtual bool loadGraphics(void);
protected:
	//None
private:
	//Inherits displayScreen
	//Inherits displayText
};
