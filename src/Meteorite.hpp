#ifndef COMPTE_HPP_
#define COMPTE_HPP_

#include<chrono>

class Meteorite {
private:
	int posX;
	float posY;
	float vitesse;
public:
	Meteorite(int x_init, float y_init, float vit);
	int getPosX() const;
	float getPosY() const;
	void fall(std::chrono::milliseconds temps);
};

#endif
