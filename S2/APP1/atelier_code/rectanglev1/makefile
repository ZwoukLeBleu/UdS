#******************************************************
# makefile No 1 du programme rectv1 (16 juin 2024)
# compilation separee simple.
#******************************************************
# Atelier APP exercice no.2 
#   But principal:
#      construire le programme rectv1
#   But secondaires:
#      make clean
#******************************************************
	
rectv1:  rectv1.o  rectangle.o
	g++ -o rectv1 rectv1.o rectangle.o
#
rectv1.o: rectv1.cpp rectangle.h
	g++ rectv1.cpp -g -c
#
rectangle.o: rectangle.cpp rectangle.h
	g++ rectangle.cpp -g -c
#
clean:
	rm  -f *.o
#
# fin du makefile
#
