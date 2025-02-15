/********
 * Fichier: canevas.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date: 01/13/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 01/13/2025
 * Description: Declaration de la classe Cercle, une derivee de Forme.
********/

#pragma once
#include "forme.h"
#include <math.h>

class Cercle : public Forme{
    private:
        double m_rayon;
        
    public:
        Cercle(double rayon=1, int x=0, int y=0);

        ~Cercle();

        double getRayon();

        void setRayon(double rayon);

        double aire();

        void afficher(ostream & s);

};