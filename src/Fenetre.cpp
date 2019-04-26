#include "Fenetre.hpp"
#include <ncurses.h>
#include<iostream>

Fenetre::Fenetre(int lignes, int colonnes){
	initscr();
	noecho();
// actualisation de la fenetre tous les 0.2 s
	halfdelay(2);
//on ajoute 2 lignes et 2 colonnes pour les bords
	fjeu = subwin(stdscr,lignes+2,colonnes+2,1,1);
	fscore = subwin(stdscr, 10,20,1,colonnes+4);
	box(fjeu,ACS_VLINE, ACS_HLINE);
	box(fscore,ACS_VLINE, ACS_HLINE);
	Nlignes = lignes;
	Ncolonnes = colonnes;
};

Fenetre::~Fenetre(){
	endwin();
	//free(fjeu);
	//free(fscore);
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
	wclear(fjeu);
	std::list<Meteorite> Meteorites = jeu.getMeteorites();
	//météorites
	if (!Meteorites.empty()) {
		for (std::list<Meteorite>::iterator it = Meteorites.begin() ; it != Meteorites.end(); ++it){
				im = it->getPosY() + 1 ;
				jm = it-> getPosX() + 1 ;
				mvwprintw(fjeu,im,jm,"o");
			}
	}

	//personnage
	Personnage perso = jeu.getPersonnage();
	ip = Nlignes;
	jp = perso.getPos()+1;
	box(fjeu,ACS_VLINE, ACS_HLINE);
	mvwprintw(fjeu,ip,jp,"p");

	//fenetre score
	wclear(fscore);
	mvwprintw(fscore,1,1,"%d vie",perso.getVie());
	box(fscore,ACS_VLINE, ACS_HLINE);

	wrefresh(fscore);
	wrefresh(fjeu);
};


