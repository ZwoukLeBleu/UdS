/********
 * Fichier: canevas.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date: 01/13/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 01/13/2025
 * Description: Implementation des methodes des classes decrites dans
 *    carre.h.
********/

#include "Carre.h"

Carre::Carre(double cote, int x, int y) : Rectangle(cote, cote, x, y){
}

//Modifie la largeur et la hauteur du carre
void Carre::setCote(double cote) {
    setWidth(cote);
    setHeight(cote);
}

//Retourne la largeur et la hauteur du carre
double Carre::getCote() {
    return getWidth();
}

//Destructeur
Carre::~Carre() {
}

//Retourne l'aire du carre
double Carre::aire() {
    return getWidth() * getHeight();
}

//Affiche les informations du carre
void Carre::afficher(ostream &s) {
    s << "Carre (x="  << ancrage.x << ", y=" << ancrage.y << ", c=" << getWidth() << ", aire="<<  aire()  << ")"<< endl;
}
