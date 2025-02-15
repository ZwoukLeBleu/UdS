#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>

using namespace std;

#include "Animal.h"
#include "Chat.h"
#include "Chien.h"
#include "Oiseau.h"
#include "Poisson.h"

class Zoo
{
private:
   int capacite;
   int nombre;
   Animal **les_animaux;
   void doubler_capacite();          //Doubler la capacite
  
public:
   Zoo(int c);
   ~Zoo();
      
   void afficher();                 //Preparer l'affichage du Zoo
   int ajouter_animal(Animal *a);   //Ajoute un animal au Zoo
   Animal* get_animal(int i);       //Retourne l'animal à une position specifique
};

#endif // ZOO_H
