#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string> 

using namespace std;

class	Animal
{
  private:
    string nom;
 
  protected:
    void set_nom(string n);
  
  public: 
    Animal(string n = "");
    virtual ~Animal();
    string get_nom();
    void presenter();
    virtual void parler() = 0;
    
}; 
#endif
