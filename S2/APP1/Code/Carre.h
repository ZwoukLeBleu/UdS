/********
 * Fichier: canevas.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date: 01/13/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 01/13/2025
 * Description: Declaration de la classe Carre, une derivee de Rectangle, qui est elle-meme derivee de Forme. 
********/

#pragma once
#include "Rectangle.h"


class Carre : public Rectangle{
    private:
    
    public:
        Carre(double cote=1, int x=0, int y=0);

        void setCote(double cote);

        double getCote();

        ~Carre();

        double aire();

        void afficher(ostream & s);
};