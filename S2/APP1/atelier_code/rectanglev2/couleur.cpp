// couleur.cpp
// Implementation file for the Couleur class.
#include "couleur.h"   // Needed for the Couleur class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function
using namespace std;

//***********************************************************
// setRed sets the value of the member variable red.        *
//***********************************************************

void Couleur::setRed(int r)
{
   if (r >= 0 && r < 256)
      red = r;
   else
   {
      cout << "Invalid red\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setGreen sets the value of the member variable green.    *
//***********************************************************

void Couleur::setGreen(int g)
{
   if (g >= 0 && g < 256)
      green = g;
   else
   {
      cout << "Invalid green\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setBlue sets the value of the member variable blue.      *
//***********************************************************

void Couleur::setBlue(int b)
{
   if (b >= 0 && b < 256)
      blue = b;
   else
   {
      cout << "Invalid blue\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// afficher display the color values (RGB).                 *
//***********************************************************

void Couleur::afficher() const
{
   cout << "Red (" << red << "), Green (" << green << "), Blue (" << blue << ")\n";
}
