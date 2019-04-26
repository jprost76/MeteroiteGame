#ifndef FENETRE_HPP
#define FENETRE_HPP
#include<vector>
#include<ncurses.h>
#include "Meteorite.hpp"
#include "Jeu.hpp"
#include "commande.hpp"

class Fenetre {
public:
	Fenetre(int lignes, int colonnes);
	~Fenetre();
	void afficherJeu(Jeu jeu) ;
	Direction listen();
	void close();
private:
	WINDOW* fjeu;
	WINDOW *fscore;
	int Nlignes;
	int Ncolonnes;
};
#endif
