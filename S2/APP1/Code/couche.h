/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 14/01/2025
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec 
 *    les specifications de Graphicus. Ce fichier fait partie de 
 *    la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include "forme.h"

const int MAX_FORMES = 5;

enum Etat{
  INITIALISE,
  ACTIVE,
  INACTIVE
};

// A completer

class Couche
{
   public:
      Couche();
      ~Couche();

      bool ajoutForme(Forme* forme);

      Forme* retraitForme(int index);

      Forme* getForme(int index);

      double aireTotal();

      bool translation(int x, int y);

      bool reinitialiser();

      bool changerEtat(Etat etat);

      Etat getEtat();

      void afficher(ostream & s);

      Coordonnee getCoordonnee();



   
   private:
      Forme* m_formes[MAX_FORMES];
      int m_nbForme;
      int m_x;
      int m_y;
      Etat m_etat;
};

#endif
