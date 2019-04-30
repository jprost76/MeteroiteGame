#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <chrono>
#include <time.h>
#include "Meteorite.hpp"
#include "Jeu.hpp"
#include "Personnage.hpp"

Jeu::Jeu(int h, int l){
	//la position an absisse de la premieère méteorite
	int xinit;
	//initialisation du genarateur de nombre aléatoire
	srand(time(NULL));
	hauteur = h;
	largeur = l;
	perso = Personnage(3,10,l);
	xinit = rand() % l;
	Meteorite m1(xinit,0,1);
	Meteorites.push_back(m1);
	nloop = 0;
}

Jeu::~Jeu(){
}


bool Jeu::update(Direction dir,std::chrono::milliseconds dt){
	bool res = true;
	std::list<Meteorite>::iterator it;
	
	switch (dir) {
	case DROITE: perso.deplacerDroite(); break;
	case GAUCHE: perso.deplacerGauche(); break;
	case RIEN:;break;
	}
	perso.move();
	
	//ajout de météorite
	if (nloop % 10 == 0) {
		Meteorite m(rand() % largeur,0,1);
		Meteorites.push_back(m);
	}
	it = Meteorites.begin() ;
	while (it != Meteorites.end()) {
		it->fall(dt);
		if ((int)(it->getPosY()) == hauteur-1) {
			if (it->getPosX() == perso.getPos()) {
				perso.enleverVie();
			}
		}
		if (it->getPosY() > hauteur-1) {
			Meteorites.erase(it++);
		} else {
			++it;
		}
	}
	if (perso.estMort()) {
		res = false;
	}
	nloop++;
	return res;
}

int Jeu::getHauteur() const {
	return hauteur;
}

int Jeu::getLargeur() const {
	return largeur;
}

std::list<Meteorite> Jeu::getMeteorites() const {
	return Meteorites;
}

Personnage Jeu::getPersonnage(){
	return perso;
}





