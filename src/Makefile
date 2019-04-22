CC=g++
EXEC=jouer

all: $(EXEC) 

jouer: Meteorite.o Jeu.o principal.o Fenetre.o Personnage.o
	$(CC) -o jouer Meteorite.o Jeu.o principal.o Fenetre.o Personnage.o -lncurses

Meteorite.o: Meteorite.cpp
	$(CC) -c Meteorite.cpp

Jeu.o: Jeu.cpp
	$(CC) -c Jeu.cpp -lncurses

Fenetre.o : Fenetre.cpp
	$(CC) -c Fenetre.cpp -lncurses

principal.o : principal.cpp
	$(CC) -c principal.cpp -std=c++11 

Personnage.o: Personnage.cpp
	$(CC) -c Personnage.cpp

clean:
	rm -rf *.o

