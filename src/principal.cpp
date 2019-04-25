#include "Meteorite.hpp"
#include "Fenetre.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include "Jeu.hpp"

#define LOOP_TIME 0.1

int main(){
	Jeu j(20,30);
	Fenetre f(20,30);

	std::cout<<"affichage 1"<<std::endl;
	f.afficherJeu(j);
	std::cout<<" fin affichage 1"<<std::endl;
	bool continu = true;
	while (continu){
		
		Direction dir = f.listen();
		continu = j.update(dir);
		f.afficherJeu(j);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}


};
