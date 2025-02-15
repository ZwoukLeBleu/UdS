/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Marc-Antoine Gauthier (gaum4233)
 * Date : 1/13/2025
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche() {
    m_nbForme = 0;
    for(unsigned int i=0; i < MAX_FORMES; i++){
        m_formes[i] = nullptr;
    }
    m_x = 0;
    m_y = 0;
    m_etat = INITIALISE;
}

//Destructeur qui supprime les formes dans l'array
Couche::~Couche() {
    for(unsigned int i=0; i < m_nbForme; i++){
        delete m_formes[i];
    }
}

//Ajoute une forme a la couche a la fin de l'array, si possible
bool Couche::ajoutForme(Forme *forme) {
    if(m_etat == INACTIVE) return false;
    if(m_nbForme >= MAX_FORMES) return false;
    if(forme == nullptr) return false;
    changerEtat(ACTIVE);
    m_formes[m_nbForme] = forme;
    m_nbForme++;
    return true;
}

//Retire une forme de la couche a l'index donne
Forme *Couche::retraitForme(int index) {
    if(index >= m_nbForme || index < 0) return nullptr;

    if(m_etat != ACTIVE) return nullptr;

    Forme* found = m_formes[index];
    for(unsigned int i=index; i < MAX_FORMES; i++){
        m_formes[i] = m_formes[i+1];
    }

    m_nbForme--;

    return found;
}

//Retourne la forme de l'index donne
Forme *Couche::getForme(int index) {
    if(index >= m_nbForme || index < 0) return nullptr;
    return m_formes[index];
}

//Retourne l'aire total de toutes les formes dans la couche
double Couche::aireTotal() {
    double sum = 0;
    for(unsigned int i=0; i < m_nbForme; i++){
        sum += m_formes[i]->aire();
    }

    return sum;
}

//Deplace toutes les formes de la couche vers les coordonnees donnees
bool Couche::translation(int x, int y) {
    //if(x == 0 || y == 0 ) return false;

    if(m_etat != ACTIVE) return false;

    m_x = x;
    m_y = y;

    for(unsigned int i=0; i < m_nbForme; i++){
        m_formes[i]->translater(m_x, m_y);
    }

    return true;
}

//Reinitialise la couche
bool Couche::reinitialiser() {
    
    if(m_etat == INITIALISE) return false;

    /*for(unsigned int i=0; i < m_nbForme; i++){
        if(m_formes[i] == nullptr) continue;
        cout << "I=" << i;
        delete m_formes;
        m_formes[i] = nullptr;
    }*/
    m_etat = INITIALISE;
    m_nbForme = 0;
    m_x = 0;
    m_y = 0;
    return true;
}

//Change l'etat de la couche pour celui donne
bool Couche::changerEtat(Etat etat) {
    if(etat == INITIALISE) return false;

    if(etat == m_etat) return false;
    m_etat = etat;
    return true;
}

//Retourne l'etat de la couche
Etat Couche::getEtat()
{
    return m_etat;
}

//Affiche les informations de la couche
void Couche::afficher(ostream &s) {
    s << "Etat : ";
    switch (m_etat)
    {
    case ACTIVE:
        s << "active" << endl;
        break;
    case INACTIVE:
        s << "inactive" << endl;
        break;
    case INITIALISE:
        s << "initialisee" << endl;
        break;
    default:
        s << "N/A" << endl;
        break;
    }

    if(m_nbForme == 0){
        s << "Couche : vide" << endl;
        return;
    }

    for(unsigned int i=0; i < m_nbForme; i++){
        m_formes[i]->afficher(s);
    }
}

//Retourne les coordonnees de la couche
Coordonnee Couche::getCoordonnee()
{
    Coordonnee c;
    c.x = m_x;
    c.y = m_y;
    return c;
}
