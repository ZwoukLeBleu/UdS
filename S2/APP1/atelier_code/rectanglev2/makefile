#******************************************************
# makefile No 1 du programme rectv2 (16 juin 2024)
# compilation separee simple.
#******************************************************
# Atelier APP exercice no.3
#   But principal:
#      construire le programme rectv2
#   But secondaires:
#      make clean
#******************************************************
	
rectv2: rectv2.o  rectangle.o couleur.o
	g++ -o rectv2 rectv2.o rectangle.o couleur.o
#
rectv2.o: rectv2.cpp rectangle.h
	g++ rectv2.cpp -g -c
#
rectangle.o: rectangle.cpp rectangle.h couleur.h
	g++ rectangle.cpp -g -c
#
couleur.o: couleur.cpp couleur.h
	g++ couleur.cpp -g -c
#
clean:
	rm  -f *.o
#
# fin du makefile
#
