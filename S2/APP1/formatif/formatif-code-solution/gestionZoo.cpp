// gestionZoo.cpp 
// formatif pratique GEN241
// GEGI - Universite de Sherbrooke

#include <iostream>
#include <string>
#include "Animal.h"
#include "Chat.h"
#include "Chien.h"
#include "Oiseau.h"
#include "Poisson.h"
#include "Zoo.h"

#define MAX_ANIMAUX   10

using namespace std;

int main() {
	
	Zoo mon_zoo(3);
		
	Chat * sylvester = new Chat("Sylvester");
	sylvester->presenter();
	sylvester->parler();
	
	mon_zoo.ajouter_animal(sylvester);
	mon_zoo.afficher();
	
    Chien * milou = new Chien("Milou");
	milou->presenter();
	milou->parler();
	
	mon_zoo.ajouter_animal(milou);
	mon_zoo.afficher();    	

	Oiseau * tweety = new Oiseau("Tweety");
	tweety->presenter();
	tweety->parler();
	
	mon_zoo.ajouter_animal(tweety);
	mon_zoo.afficher();    	
	
	Poisson * nemo = new Poisson("Nemo");
	nemo->presenter();
	nemo->parler();
	
	mon_zoo.ajouter_animal(nemo);
	mon_zoo.afficher();    	
	
    Chien * snoopy = new Chien("Snoopy");
	snoopy->presenter();
	snoopy->parler();
	
	mon_zoo.ajouter_animal(snoopy);
	mon_zoo.afficher();    	
	
	Animal * un_animal;
	un_animal = mon_zoo.get_animal (2);
	
	cout << "L'animal à la postion 2 est :" << endl;
	un_animal->presenter();
	un_animal->parler();
	
    return 0;
}
