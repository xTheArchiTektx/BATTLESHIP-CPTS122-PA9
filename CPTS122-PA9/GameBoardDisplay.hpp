#pragma once
#include "PA9.hpp"
#include "SplashScreen.hpp"

class GameBoardDisplay : public SplashScreen
{
public:
	//inherits show()
	virtual bool loadGraphics(void);
protected:
	

private:
	//Inherits displayScreen
	//Inherits displayText
};
