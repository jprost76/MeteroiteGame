#include <iostream>
#include <stdio.h>
#include <ncurses.h>
#include "Meteorite.hpp"
#include "Jeu.hpp"
#include "Personnage.hpp"

Jeu::Jeu(int h, int l){
	hauteur = h;
	largeur = l;
	perso = Personnage(3,10,l);
	Meteorite m1(10,1),m2(12,3);
	Meteorites.push_back(m1);
	Meteorites.push_back(m2);
}

Jeu::~Jeu(){
}

bool Jeu::loop(){
	//
	bool res = true;
	for (std::vector<Meteorite>::iterator it = Meteorites.begin() ; it != Meteorites.end(); ++it){
			it->fall();
			if (it->getPosY() > hauteur) {
				res = false;
			}
		}
	return res;
}

bool Jeu::update(Direction dir){
	bool res = true;
	switch (dir) {
	case DROITE: perso.deplacerDroite(); break;
	case GAUCHE: perso.deplacerGauche(); break;
	case RIEN:;break;
	}
	perso.move();
	if (!Meteorites.empty()) {
		for (std::vector<Meteorite>::iterator it = Meteorites.begin() ; it != Meteorites.end(); ++it){
					it->fall();
					if (it->getPosY() > hauteur) {
						Meteorites.erase(it);
					}
				}
	}
	if (perso.estMort()) {
		res = false;
	}
	return res;
}

int Jeu::getHauteur() const {
	return hauteur;
}

int Jeu::getLargeur() const {
	return largeur;
}

std::vector<Meteorite> Jeu::getMeteorites() const {
	return Meteorites;
}

Personnage Jeu::getPersonnage(){
	return perso;
}





