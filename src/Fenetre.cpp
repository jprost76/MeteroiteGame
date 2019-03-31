#include "Fenetre.hpp"
#include<iostream>

Fenetre::Fenetre(){
	//remplissage du centre du tableau
	int i,j;
		for (i=1;i<hauteur+1;i++) {
			for (j=1;j<largeur+1;j++) {
				tab[i][j]=' ';
			}
		}
	//remplissage des bords
	for (j=0;j<largeur+2;j++){
		tab[0][j] = '=';
		tab[hauteur+1][j] = '=';
	}
	for (i=1;i<hauteur+1;i++){
		tab[i][0] = '|';
		tab[i][largeur+1] = '|';
	}
};

Fenetre::~Fenetre(){
};

void Fenetre::addMeteorite(Meteorite m){
	Meteorites.push_back(m);
};

void Fenetre::update(){
	//remplissage du centre du tableau
		int i,j,im,jm;
			for (i=1;i<hauteur;i++) {
				for (j=1;j<largeur;j++) {
					tab[i][j]=' ';
				}
			}
	for (std::vector<Meteorite>::iterator it = Meteorites.begin() ; it != Meteorites.end(); ++it){
		im = it->getPosY() + 1; //décalage de 1 pour prendre en compte les bords
		jm = it-> getPosX() +1;
		tab[im][jm] = '*';
	}
}

void Fenetre::afficher() const {
	int i,j;
	for (i=0;i<hauteur+2;i++) {
		for (j=0;j<largeur+2;j++) {
			std::cout<<tab[i][j];
		}
		std::cout<<std::endl;
	}
};
