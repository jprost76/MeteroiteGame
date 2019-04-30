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
	std::chrono::time_point<std::chrono::high_resolution_clock> t1,t2;
	std::chrono::milliseconds delta_t;
	f.afficherJeu(j);
	bool continu = true;
	while (continu){
		t1 = std::chrono::high_resolution_clock::now();
		Direction dir = f.listen();
		t2 = std::chrono::high_resolution_clock::now();
		delta_t = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		continu = j.update(dir,delta_t);
		f.afficherJeu(j);
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
return 1;

};
