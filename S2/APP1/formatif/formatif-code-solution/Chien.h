#ifndef CHIEN_H
#define CHIEN_H

#include <iostream>
#include <string> 
#include "Mammifere.h"

using namespace std;

class Chien: public Mammifere
{
  public:
    Chien(string n);
    void parler();
}; 
#endif
