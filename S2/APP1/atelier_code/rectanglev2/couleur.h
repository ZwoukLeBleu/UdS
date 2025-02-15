// couleur.h
// Specification de la classe Couleur. 
#ifndef COULEUR_H
#define COULEUR_H

// Couleur class declaration.

class Couleur
{
   private:
      int red = 0;
      int green = 0;
	  int blue = 0;
   public:
      void setRed(int);
	  void setGreen(int);
	  void setBlue(int);
      void afficher() const;
};

#endif
