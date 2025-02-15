#ifndef _MAMMIFERE_H
#define _MAMMIFERE_H

#include <iostream>
#include <string> 

#include "Animal.h"

using namespace std;

class	Mammifere: public Animal
{ 	
  public: 
    Mammifere();
    virtual ~Mammifere();
    virtual void parler() = 0;
}; 
#endif
