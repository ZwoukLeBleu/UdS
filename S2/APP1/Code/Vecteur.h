/********
 * Fichier: canevas.cpp
 * Auteurs: Marc-Antoine Gauthier
 * Date: 01/13/2025 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakary Romdhane (gaum4233, romz6050)
 * Date : 01/13/2025
 * Description: Declaration de la classe Vecteur, une classe generique qui permet de stocker
 *      des elements d'un type donnee lors de linitialisation de l'objet, grace des templates.
 *      Cette classe est utilisee dans le canevas pour stocker les couches.
********/

#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Vecteur{
    private:
        int m_size;
        int m_capacity;
        T *m_arr;
    public:
        Vecteur();
        ~Vecteur();

        const bool addItem(T item);

        T removeItem(int index);

        const bool isEmpty();

        void reset();

        void doubleCapacity();

        const int getSize();

        T getItem(int index);

        void show(std::ostream & s);



};

#include "Vecteur.tpp"
