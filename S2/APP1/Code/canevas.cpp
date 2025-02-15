/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet 
 * Date: 13 juin 2024 (creation)
 * Modifie par : Marc-Antoine Gauthier (gaum4233)
 * Date : 1/13/2025
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas() {
   m_couches = new Vecteur<Couche*>();
}

Canevas::~Canevas() {
   delete m_couches;
}

//Permets d'ajouter une couche au vecteur de couche
bool Canevas::ajouterCouche()
{
   bool temp = m_couches->addItem(new Couche());
   if(!temp) return temp;
   if(m_couches->getSize() == 1){
      m_couches->getItem(0)->changerEtat(ACTIVE);
   }
   return temp;
}

//Permets de retirer une couche d'un index donne du vecteur de couche
bool Canevas::retirerCouche(int index)
{
   if(index >= m_couches->getSize() || index < 0) return false;
   Couche* c = m_couches->removeItem(index);
   
   return true;
}

//reinitialise toutes les couches
bool Canevas::reinitialiser()
{
   /*for(unsigned int i=0; i < m_couches->getSize(); i++){
      m_couches->getItem(i)->reinitialiser();
   }*/
   m_couches->reset();
   return true;
}

//reinitialise une couche d'un index donne
bool Canevas::reinitialiserCouche(int index)
{
   if(index >= m_couches->getSize() || index < 0) return false;
   Couche* c = m_couches->getItem(index);
   return c->reinitialiser();
}

//Active une couche d'un index donne
bool Canevas::activerCouche(int index)
{
   if(index >= m_couches->getSize() || index < 0) return false;
   for(unsigned int i=0; i < m_couches->getSize(); i++){
      if (m_couches->getItem(i)->getEtat() == ACTIVE){ 
         m_couches->getItem(i)->changerEtat(INACTIVE);
      }
   }
   return m_couches->getItem(index)->changerEtat(ACTIVE);
}

//Desactive une couche d'un index donne
bool Canevas::desactiverCouche(int index)
{
   if(index >= m_couches->getSize() || index < 0) return false;

   if(!m_couches->getItem(index)->changerEtat(INACTIVE)) return false;
   return true;
}

//Ajoute une forme a la couche active
bool Canevas::ajouterForme(Forme *p_forme)
{
   Couche* found = nullptr;
   for(unsigned int i=0; i < m_couches->getSize(); i++){
      if(m_couches->getItem(i)->getEtat() == ACTIVE){
         found = m_couches->getItem(i);
         break;
      }
   }

   if(found == nullptr) return false;

   return found->ajoutForme(p_forme);
}

//Retire la forme d'un index donne de la couche active
bool Canevas::retirerForme(int index)
{
   Couche* found = nullptr;
   for(unsigned int i=0; i < m_couches->getSize(); i++){
      if(m_couches->getItem(i)->getEtat() == ACTIVE){
         found = m_couches->getItem(i);
         break;
      }
   }

   if(found == nullptr) return false;

   return found->retraitForme(index);
}

//Retourne l'aire total de toutes les couches
double Canevas::aire()
{
   double sum=0;
   for(unsigned int i=0; i < m_couches->getSize(); i++){
      sum += m_couches->getItem(i)->aireTotal();
   }

   return sum;
}

//Deplace toutes les formes de la couche active par les coordonnees donnees
bool Canevas::translater(int deltaX, int deltaY)
{
   Couche* found = nullptr;
   for(unsigned int i=0; i < m_couches->getSize(); i++){
      if(m_couches->getItem(i)->getEtat() == ACTIVE){
         found = m_couches->getItem(i);
         break;
      }
   }

   if(found == nullptr) return false;

   

   return found->translation(deltaX, deltaY);;
}

//Affiche les informations de toutes les couches
void Canevas::afficher(ostream & s) {
   /*if(m_couches->isEmpty()) {
      s << "----- Aucune couche -----" << endl;
      return;
   }


   for(unsigned int i=0; i < m_couches->getSize(); i++){
      s << "----- Couche " << i << " -----" << endl;
      m_couches->getItem(i)->afficher(s);
   }*/
  m_couches->show(s);
}
