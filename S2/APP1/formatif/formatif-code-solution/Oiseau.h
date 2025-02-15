#ifndef OISEAU_H
#define OISEAU_H

#include <iostream>
#include <string> 
#include "Animal.h"

using namespace std;

class	Oiseau: public Animal
{ 
  public:
    Oiseau(string n);
    void parler();
};
#endif
