#ifndef FENETRE_HPP
#define FENETRE_HPP
#define hauteur 30
#define largeur 50
#include<vector>
#include "Meteorite.hpp"

class Fenetre {
private:
	char tab[hauteur+2][largeur+2];
	std::vector<Meteorite> Meteorites;
public:
	Fenetre();
	~Fenetre();
	void addMeteorite(const Meteorite m);
	void update();
	void afficher() const;
};
#endif
