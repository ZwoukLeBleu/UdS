#
gestionZoo:  gestionZoo.o  Animal.o Mammifere.o Chat.o Chien.o Oiseau.o Poisson.o Zoo.o 
	g++ -o gestionZoo gestionZoo.o  Animal.o Mammifere.o Chat.o Chien.o Oiseau.o Poisson.o Zoo.o 
#
gestionZoo.o: gestionZoo.cpp Animal.h Mammifere.h Chat.h Chien.h Oiseau.h Poisson.h Zoo.h
	g++ gestionZoo.cpp -g -c
#
Animal.o: Animal.cpp Animal.h
	g++ Animal.cpp -g -c
#
Mammifere.o: Mammifere.cpp Mammifere.h Animal.h
	g++ Mammifere.cpp -g -c

#
Chat.o: Chat.cpp Chat.h Mammifere.h Animal.h
	g++ Chat.cpp -g -c
#
Chien.o: Chien.cpp Chien.h Mammifere.h Animal.h
	g++ Chien.cpp -g -c
#
Oiseau.o: Oiseau.cpp Oiseau.h Animal.h
	g++ Oiseau.cpp -g -c
#
Poisson.o: Poisson.cpp Poisson.h Animal.h
	g++ Poisson.cpp -g -c
#
Zoo.o: Zoo.cpp Zoo.h Animal.h Chat.h Chien.h Oiseau.h Poisson.h Zoo.h
	g++ Zoo.cpp -g -c	
#
clean:
	rm  -f *.o		
#
# fin du makefile
#
