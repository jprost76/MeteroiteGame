CC=g++
EXEC=jouer

all: $(EXEC) 

jouer: Meteorite.o Jeu.o principal.o Fenetre.o Personnage.o
	$(CC) -o jouer Meteorite.o Jeu.o principal.o Fenetre.o Personnage.o -lncurses -fPIC -no-pie -std=c++11

Meteorite.o: Meteorite.cpp
	$(CC) -c Meteorite.cpp -std=c++11

Jeu.o: Jeu.cpp
	$(CC) -c Jeu.cpp -lncurses -std=c++11

Fenetre.o : Fenetre.cpp
	$(CC) -c Fenetre.cpp -lncurses -fPIC -no-pie -std=c++11

principal.o : principal.cpp
	$(CC) -c principal.cpp -std=c++11 

Personnage.o: Personnage.cpp
	$(CC) -c Personnage.cpp

clean:
	rm -rf *.o

