#
# Auteur: C.-A. Brunet
# Date: 13 juin 2024
# Modifie par : Marc-Antoine Gauthier et Zkary Romdhane (gaum4233, romz6050)
# Date : 14/01/2025
# Description: compilation de graphicus-02. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-02: graphicus-02.o tests.o canevas.o couche.o forme.o Rectangle.o Vecteur.o Carre.o Cercle.o
	g++ -o graphicus-02 graphicus-02.o Vecteur.o tests.o canevas.o couche.o forme.o Rectangle.o Carre.o Cercle.o 

graphicus-02.o: graphicus-02.cpp canevas.h couche.h forme.h
	g++ -c graphicus-02.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h forme.h
	g++ -c couche.cpp

forme.o: forme.cpp forme.h
	g++ -c forme.cpp

Rectangle.o: Rectangle.cpp Rectangle.h forme.h
	g++ -c Rectangle.cpp

Carre.o: Carre.cpp Carre.h Rectangle.h
	g++ -c Carre.cpp

Cercle.o: Cercle.cpp Cercle.h forme.h
	g++ -c Cercle.cpp

Vecteur.o: Vecteur.cpp Vecteur.h Vecteur.tpp
	g++ -c Vecteur.cpp

clean:
	rm  -f *.o
