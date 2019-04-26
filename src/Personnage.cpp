#include "Personnage.hpp"

Personnage::Personnage(){
	pos = 1;
	vie = 1;
	vit = 0;
	xlim = 0;
};

Personnage::Personnage(int vie_init, int pos_init,int lim){
	vie = vie_init;
	pos = pos_init;
	vit = 0;
	xlim = lim;
	//
}

Personnage::~Personnage(){};

void Personnage::setPos(int pos_new){
	pos = pos_new;
}

void Personnage::enleverVie(){
	vie -= 1;
}

int Personnage::getPos(){
	return pos;
}

int Personnage::getVie(){
	return vie;
}

void Personnage::deplacerGauche(){
	vit -= VIT_PERSO;
}

void Personnage::deplacerDroite(){
	vit += VIT_PERSO;
}

void Personnage::finDeplacement(){
	vit = 0;
}

void Personnage::move() {
	pos += vit;
	vit=0;
	if (pos<0) {
		pos = 0;
	} else if (pos>=xlim) {
		pos = xlim-1;
	}
}

bool Personnage::estMort() {
	return (vie <= 0);
}
