#include "Meteorite.hpp"
#include "Fenetre.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include "Jeu.hpp"


int main(){
	Jeu j(20,30);
	Fenetre f(20,30);

	f.afficherJeu(j);
	bool continu = true;
	while (continu){
		Direction dir = f.listen();
		std::cout<<"fin jeu.listen"<<std::endl;
		continu = j.update(dir);
		f.afficherJeu(j);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}


};
