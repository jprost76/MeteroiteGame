#ifndef CONTROLEUR_HPP
#define CONTROLEUR_HPP

enum Direction{droite, gauche};

class Controlleur {
private:
	char action;
public:
	Direction getAction();

};
#endif
