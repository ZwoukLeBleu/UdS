/********
 * Fichier: canevas.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date: 01/13/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 01/13/2025
 * Description: Declaration de la classe Rectangle, une derivee de Forme.
********/

#pragma once
#include "forme.h"


class Rectangle : public Forme{
    private:
        double m_width;
        double m_height;

    public:

        Rectangle(double width=1, double height=1, int x=0, int y=0);

        virtual double aire();

        virtual void afficher(ostream & s);

        double getWidth();

        double getHeight();
        void setWidth(double width);

        void setHeight(double height);

        ~Rectangle();

};