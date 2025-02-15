#ifndef POISSON_H
#define POISSON_H

#include <iostream>
#include <string> 
#include "Animal.h"

using namespace std;



class	Poisson: public Animal
{
  public:
    Poisson (string n);
    void parler();
}; 
#endif
