#ifndef COMPTE_HPP_
#define COMPTE_HPP_

class Meteorite {
private:
	int posX;
	int posY;
	int size;
public:
	Meteorite(int x_init, int y_init, int s);
	int getPosX() const;
	int getPosY() const;
	void fall();
};

#endif
