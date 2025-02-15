/********
 * Fichier: Vecteur.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date:  6/12/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier (gaum4233)
 * Date : 1/12/2025
 * Description: Implementation des methodes de la classe Vecteur présente dans
 * le fichier Vecteur.h
********/
#include "Vecteur.h"

//Constructeur
template <typename T>
Vecteur<T>::Vecteur() {
    m_size = 0;
    m_capacity = 2;
    m_arr = new T[m_capacity];
}

//Destructeur
template <typename T>
Vecteur<T>::~Vecteur() {
    delete [] m_arr;
}

//Ajoute un item au vecteur a sa fin. Double la capacite si necessaire
template <typename T>
const bool Vecteur<T>::addItem(T item) {
    if(m_size == m_capacity){
        doubleCapacity();
    }
    m_arr[m_size++] = item; //incremente m_size seulement apres avoir assigner sa valeur dans m_arr[]
    return true;
}

//Retire un item du vecteur a l'index donnee
template <typename T>
T Vecteur<T>::removeItem(int index) {
    if(index >= m_size || index < 0) return 0;

    T temp = m_arr[index];

    for(unsigned int i=index; i < m_size-1; i++){
        m_arr[i] = m_arr[i+1];
    }
    m_size--;
    return temp;
}

//Verifie si le vecteur est vide
template <typename T>
const bool Vecteur<T>::isEmpty() {
    return m_size > 0 ? false : true; //ternary
}

//Remet le vecteur a son etat initial
template <typename T>
void Vecteur<T>::reset() {
    delete [] m_arr;
    m_capacity = 2;
    m_size = 0;
    m_arr = new T[2];

}

//Double la capacite du vecteur
template <typename T>
void Vecteur<T>::doubleCapacity() {
    T* newArr = new T[m_capacity*2];
    for(unsigned int i=0; i < m_size; i++){
        newArr[i] = m_arr[i]; //copie l'array dans le plus grand
    }
    delete [] m_arr;
    m_arr = newArr;
    m_capacity *=2;
}

//Retourne la taille du vecteur
template <typename T>
const int Vecteur<T>::getSize() {
    return m_size;
}

//Retourne l'item a l'index donne
template <typename T>
T Vecteur<T>::getItem(int index) {
    if(index >= m_size || index < 0) return 0;

    return m_arr[index];
}

//Affiche ??
template <typename T>
void Vecteur<T>::show(std::ostream &s) {
    if(isEmpty()) {
      s << "----- Aucune couche -----" << endl;
      return;
   }


   for(unsigned int i=0; i < getSize(); i++){
      s << "----- Couche " << i << " -----" << endl;
      getItem(i)->afficher(s);
   }
}
