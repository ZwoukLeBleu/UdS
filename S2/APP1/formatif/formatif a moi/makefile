out: main.o zoo.o animal.o oiseau.o poisson.o chat.o chien.o
	g++ -o main.o zoo.o animal.o oiseau.o poisson.o chat.o chien.o

main.o: main.cpp animal.h zoo.h
	g++ -c main.cpp 

zoo.o: zoo.cpp zoo.h animal.h
	g++ -c zoo.cpp

animal.o: animal.cpp animal.h
	g++ -c animal.cpp

poisson.o: poisson.cpp poisson.h animal.h
	g++ -c poisson.cpp

chat.o: chat.cpp chat.h animal.h
	g++ -c chat.cpp

chien.o: chien.cpp chien.h animal.h
	g++ -c chien.cpp

oiseau.o: oiseau.cpp oiseau.h animal.h
	g++ -c oiseau.cpp

