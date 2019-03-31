//============================================================================
// Name        : Meteorite.cpp
// Author      : jprost
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Meteorite.hpp"

Meteorite::Meteorite(int x_init, int s) {
	posX = x_init;
	posY = 0;
	size = s;
};

int Meteorite::getPosX() const{
	return posX;
}

int Meteorite::getPosY() const{
	return posY;
}
