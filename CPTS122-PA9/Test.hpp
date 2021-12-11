#pragma once

#include "Game.hpp"

class Test
{
public:
	void ifShipOutOfBounds(void); // to test if ship sprite goes out of bounds.
	void ifPlaceOutOfBounds(void); // to test if user placed coordinates out of bounds.
	void ifNoInput(void); // to test if user hit enter without coords.
	void ifShipsCollide(void); // to test if User placed conflicting ships
	void ifHitTwice(void); // test if user placed same square twice.
};