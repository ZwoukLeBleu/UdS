/********
 * Fichier: canevas.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date: 01/13/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 01/13/2025
 * Description: Implementation des methodes des classes decrites dans cercle.h.
********/

#include "Cercle.h"

Cercle::Cercle(double rayon, int x, int y) : Forme(x, y){
    m_rayon = rayon;
}

//Destructeur
Cercle::~Cercle() {
}

//Retourne le rayon du cercle
double Cercle::getRayon() {
    return m_rayon;
}

//Modifie le rayon du cercle
void Cercle::setRayon(double rayon) {
    m_rayon = rayon;
}

//Retourne l'aire du cercle
double Cercle::aire() {
    return pow(m_rayon, 2) * M_PI;
}

//Affiche les informations du cercle
void Cercle::afficher(ostream &s) {
    s << "Cercle (x="  << ancrage.x << ", y=" << ancrage.y << ", r=" << m_rayon << ", aire="<<  aire()  << ")"<< endl;
}
