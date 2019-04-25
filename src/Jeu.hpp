

#ifndef JEU_HPP
#define JEU_HPP
#include<vector>
#include <SDL2/SDL.h>
#include "Meteorite.hpp"
#include "Personnage.hpp"
#include "commande.hpp"

class Jeu {
private:
	int hauteur;
	int largeur;
	std::vector<Meteorite> Meteorites;
	Personnage perso;

public:
	Jeu(int h, int l);
	~Jeu();
	bool loop();
	int getHauteur() const;
	int getLargeur() const;
	std::vector<Meteorite> getMeteorites() const;
	Personnage getPersonnage();
	bool update(Direction dir);
};
#endif
