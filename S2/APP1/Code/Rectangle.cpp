/********
 * Fichier: canevas.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date: 01/13/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 01/13/2025
 * Description: Implementation des methodes des classes decrites dans rectangle.h.
********/

#include "Rectangle.h"


Rectangle::Rectangle(double width, double height, int x, int y) : Forme(x,y) {
    m_width = width;
    m_height = height;
}

//Modifie la largeur du rectangle vers la valeur donnee
void Rectangle::setWidth(double width) {
    m_width = width;
}

//Modifie la hauteur du rectangle vers la valeur donnee
void Rectangle::setHeight(double height) {
    m_height = height;
}

//Retourne la largeur du rectangle
double Rectangle::getWidth() {
    return m_width;
}

//Retourne la hauteur du rectangle
double Rectangle::getHeight() {
    return m_height;
}

//Retourne l'aire du rectangle
double Rectangle::aire(){
    return m_width * m_height;
}

//Affiche les informations du rectangle
void Rectangle::afficher(ostream &s) {
    s << "Rectangle (x="  << ancrage.x << ", y=" << ancrage.y << ", l=" << getWidth() << ", h="  << getHeight() << ", aire="<<  aire()  << ")"<< endl;
}

//Destructeur
Rectangle::~Rectangle() {
}
