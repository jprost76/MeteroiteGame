#include "Meteorite.hpp"
#include "Fenetre.hpp"
#include<iostream>


int main(){
	Meteorite  m(10,3);
	Fenetre f;
	f.addMeteorite(m);
	f.update();
	f.afficher();
};
