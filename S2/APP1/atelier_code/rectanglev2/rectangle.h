// rectangle.h (based on Rectangle version 1 Gaddis ed 6  page 754)
// Specification file for the Rectangle class. 
#ifndef RECTANGLE_H
#define RECTANGLE_H

// Rectangle class declaration.
#include "couleur.h"  // Needed by Rectangle class

class Rectangle
{
   private:
      double width;
      double length;
	  Couleur color;
   public:
      void setWidth(double);
      void setLength(double);
	  void setCouleur(int red, int green, int blue);
	  void afficherCouleur() const;
	  
      double getWidth() const;
      double getLength() const;
      double getArea() const;
};

#endif
