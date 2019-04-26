
#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

class Personnage {
private:
	int vie;
	int pos;
	int vit;
	int xlim;
public:
	static const int VIT_PERSO = 1;
	Personnage();
	Personnage(int vie_init, int pos_init, int lim);
	~Personnage();
	void enleverVie();
	void setPos(int pos_new);
	void deplacerGauche();
	void deplacerDroite();
	void finDeplacement();
	int getPos();
	int getVie();
	void move();
	bool estMort();
};

#endif
