#include "Evaluation.h"
#include <iostream>
#include <iomanip>

using namespace std;

char Evaluation::getCote() const
{
   char cote;
   
   if (resultat > 89)
      cote = 'A';
   else if (resultat > 79)
      cote = 'B';
   else if (resultat > 69)
      cote = 'C';
   else if (resultat > 59)
      cote = 'D';
   else
      cote = 'F';
   
   return cote;
}

void Evaluation::afficher()
{
   cout << setprecision(1) << fixed;
   cout << "Le score numerique est " << this->getResultat() << "." << endl;
   cout << "La cote est  " << this->getCote() << "." << endl;
}

