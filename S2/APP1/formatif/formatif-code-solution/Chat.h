#ifndef CHAT_H
#define CHAT_H

#include <iostream>
#include <string> 
#include "Mammifere.h"

using namespace std;

class Chat: public Mammifere
{
  public: 
    Chat(string n);
    void parler();
    
};
#endif
