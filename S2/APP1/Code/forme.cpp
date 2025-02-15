/********
 * Fichier: forme.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    forme.h. Les methodes de la classe Forme ne doivent pas etre
 *    modifiees. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "forme.h"

//Classe de base pour les formes geometriques
Forme::Forme(int x1, int y1)
{
  ancrage.x = x1;
  ancrage.y = y1;
}
//Destructeur
Forme::~Forme()
{
}

//Deplace la forme de deltaX et deltaY
void Forme::translater(int deltaX, int deltaY)
{
   ancrage.x += deltaX;
   ancrage.y += deltaY;
}

//Retourne l'ancrage de la forme
Coordonnee Forme::getAncrage()
{
   return ancrage;
}

//Modifie l'ancrage de la forme avec la coordonnee c
void Forme::setAncrage(Coordonnee c)
{
   ancrage = c;
}
