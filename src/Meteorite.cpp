//============================================================================
// Name        : Meteorite.cpp
// Author      : jprost
//============================================================================

#include <iostream>
#include<chrono>
#include "Meteorite.hpp"

Meteorite::Meteorite(int x_init, float y_init,float vit) {
	posX = x_init;
	posY = y_init;
	vitesse = vit;
};

int Meteorite::getPosX() const{
	return posX;
}

float Meteorite::getPosY() const{
	return posY;
}

void Meteorite::fall(std::chrono::milliseconds temps){
	posY = posY+((float)temps*vitesse);
}
