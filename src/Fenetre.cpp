#include "Fenetre.hpp"
#include <ncurses.h>
#include<iostream>

Fenetre::Fenetre(int lignes, int colonnes){
	initscr();
	noecho();
	halfdelay(2);
//on ajoute 2 lignes et 2 colonnes pour les bords
	boite = subwin(stdscr,lignes+2,colonnes+2,1,1);
	box(boite,ACS_VLINE, ACS_HLINE);
	Nlignes = lignes;
	Ncolonnes = colonnes;
};

Fenetre::~Fenetre(){
	endwin();
	free(boite);
};

Direction Fenetre::listen() {
	char input;
	Direction res = RIEN;
	input = getch();
	if( input=='q' )
	{
	   res = GAUCHE;
	} else if (input == 'd' ) {
		res = DROITE;
	}
	return res;
}

void Fenetre::afficherJeu(Jeu jeu)  {
	int im, jm, ip,jp;
	wclear(boite);
	std::list<Meteorite> Meteorites = jeu.getMeteorites();
	//météorites
	if (!Meteorites.empty()) {
		for (std::list<Meteorite>::iterator it = Meteorites.begin() ; it != Meteorites.end(); ++it){
				im = it->getPosY() + 1 ;
				jm = it-> getPosX() + 1 ;
				mvwprintw(boite,im,jm,"o");
			}
	}

	//personnage
	Personnage perso = jeu.getPersonnage();
	ip = Nlignes;
	jp = perso.getPos()+1;
	box(boite,ACS_VLINE, ACS_HLINE);
	mvwprintw(boite,ip,jp,"p");


	wrefresh(boite);
};
