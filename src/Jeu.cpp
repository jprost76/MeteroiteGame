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
	for (std::vector<Meteorite>::iterator it = Meteorites.begin() ; it != Meteorites.end(); ++it){
				it->fall();
				if (it->getPosY() > hauteur) {
					Meteorites.erase(it);
				}
			}
		return res;
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

void Jeu::handleEvent(SDL_Event& e){
	//If a key was pressed
		if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
	    {
	        //Adjust the velocity
	        switch( e.key.keysym.sym )
	        {
	            case SDLK_LEFT: perso.deplacerGauche(); break;
	            case SDLK_RIGHT: perso.deplacerDroite(); break;
	        }
	    }
	    //If a key was released
	   /* else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
	    {
	        //Adjust the velocity
	        switch( e.key.keysym.sym )
	        {
	            case SDLK_LEFT: perso.finDeplacement(); break;
	            case SDLK_RIGHT: perso.finDeplacement(); break;
	        }
	    }*/
}



