//============================================================================
// Name        : Meteorite.cpp
// Author      : jprost
//============================================================================

#include <iostream>
#include "Meteorite.hpp"

Meteorite::Meteorite(int x_init, int y_init,int s) {
	posX = x_init;
	posY = y_init;
	size = s;
};

int Meteorite::getPosX() const{
	return posX;
}

int Meteorite::getPosY() const{
	return posY;
}

void Meteorite::fall(){
	posY = posY+1;
}
