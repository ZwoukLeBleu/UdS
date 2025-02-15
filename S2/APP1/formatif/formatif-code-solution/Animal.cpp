#include "Animal.h"

void Animal::set_nom(string n)
{	nom = n;  }

string Animal::get_nom()
{   return nom;  }

Animal::Animal(string n)
{ cout << "Voici un Animal " << nom << endl; }

Animal::~Animal()
{ cout << "Adieu Animal " << nom << endl; }

void Animal::presenter()
{ cout << "Je m'appelle: " << nom << endl; }


