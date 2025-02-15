/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Marc-Antoine Gauthier et Zakar Romdhane (gaum4233, romz6050)
 * Date : 1/13/2025
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

void Tests::tests_unitaires_formes()
{
   // Tests sur les formes geometriques
   Rectangle rec = Rectangle(10, 11 ,2,3);
   rec.afficher(cout);

   Carre car = Carre(9, 1 ,5);
   car.afficher(cout);

   Cercle cer = Cercle(5, 3 ,6);
   cer.afficher(cout);
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
   Couche c = Couche();
   c.afficher(cout);

   c.changerEtat(ACTIVE);
   c.afficher(cout);

   Rectangle r = Rectangle(2,2 ,5,4);
   c.changerEtat(INACTIVE);
   cout << "ETAT INACTIF TENTATIVE AJOUT FORME :" << c.ajoutForme(&r) << endl;

   c.changerEtat(ACTIVE);
   cout << "ETAT ACTIF TENTATIVE AJOUT FORME : " << c.ajoutForme(&r) << endl;

   c.afficher(cout);

   cout << "TENTATIVE REINITIALISATION : " << c.reinitialiser() << endl;
   c.afficher(cout);
}

void Tests::tests_unitaires_vecteur()
{
   Vecteur<Couche*> v = Vecteur<Couche*>();
   cout << "GRANDEUR : " << v.getSize() << endl;

   cout << "ALLER CHERCHER INDEX 5 : " << v.getItem(5) << endl;

   Couche* c = new Couche();
   Rectangle r1 = Rectangle(1,2,3,4);
   c->ajoutForme(&r1);
   cout << "AJOUTER AU VECTEUR" << endl;
   v.addItem(c);
   Couche* c1 = new Couche();
   Rectangle r2 = Rectangle(5,6,7,8);
   Carre c3 = Carre(1,2,3);

   c1->ajoutForme(&r2);
   cout << "AJOUTER AU VECTEUR PRISE 2" << endl;
   v.addItem(c1);

   cout << "GRANDEUR : " << v.getSize() << endl;

   cout << "AFFICHAGE ELEMENT 0 : " << endl;
   v.getItem(0)->afficher(cout);

   cout << "AFFICHAGE ELEMENT 1 : " << endl;
   v.getItem(1)->afficher(cout);

   cout << "RETRAIT ELEMENT 0 : ";
   v.removeItem(0);
   cout << v.getSize() << endl;

   cout << "AFFICHAGE ELEMENT 0 :" << endl;
   v.getItem(0)->afficher(cout);
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_couche();
   tests_unitaires_vecteur();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << boolalpha; 
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   Canevas* canevas = new Canevas();
   cout << "ETAPE 1 :" << endl;
   canevas->afficher(cout);
   cout << "ETAPE 2 : Aire : " << canevas->aire() << endl;

   cout << "ETAPE 3 : " << endl;
   for(unsigned int i=0 ; i< 5; i++){
      cout << "3." << i << " : " << canevas->ajouterCouche() << endl;
   }

   cout << "ETAPE 4 : " << endl;
   canevas->afficher(cout);
   cout << "ETAPE 5 : AIRE : " << canevas->aire() << endl;
   cout << "ETAPE 6 : " << canevas->activerCouche(2) << endl;
   cout << "ETAPE 6.1 : Cercle (r=5, x=0, y=1). Success? : " << canevas->ajouterForme(new Cercle(5,0,1)) << endl;
   cout << "ETAPE 6.2 : Carre (c=6, x=1, y=2). Success? : " << canevas->ajouterForme(new Carre(6,1,2)) << endl;
   cout << "ETAPE 6.3 : Rectangle (l=4, h=9, x=2, y=3). Success? : " << canevas->ajouterForme(new Rectangle(4,9,2,3)) << endl;
   cout << "ETAPE 7 : " << canevas->activerCouche(1) << endl;
   cout << "ETAPE 7.1 : Rectangle (l=12, h=3, x=0, y=0). Success? : " << canevas->ajouterForme(new Rectangle(12,3,0,0)) << endl;
   cout << "ETAPE 8 : " << endl;
   canevas->afficher(cout);
   cout << "ETAPE 9 : AIRE : " << canevas->aire() << endl;

   cout << "ETAPE 10 : " << canevas->activerCouche(0) << endl;
   cout << "ETAPE 10.1 : Rectangle (l=1, h=1, x=0, y=0). Success? : " << canevas->ajouterForme(new Rectangle(1,1, 0, 0)) << endl;
   cout << "ETAPE 10.2 : Carre (c=1, x=0, y=0). Success? : " << canevas->ajouterForme(new Carre(1,0,0)) << endl;
   cout << "ETAPE 10.2 : Cercle (c=1, x=0, y=0). Success? : " << canevas->ajouterForme(new Cercle(1,0,0)) << endl;

   cout << "ETAPE 11 : " << canevas->activerCouche(2) << endl ;
   canevas->translater(2,1);
   cout << "ETAPE 12 : " << endl;
   canevas->afficher(cout);
   cout << "ETAPE 13 : AIRE :" << canevas->aire() << endl;

   cout << "ETAPE 14 : " << canevas->activerCouche(0) << endl;
   canevas->retirerForme(1);
   cout << "ETAPE 15 : " << canevas->reinitialiserCouche(1) << endl;
   cout << "ETAPE 16 : " << canevas->activerCouche(2) << endl;
   cout << "ETAPE 17 : " << canevas->retirerCouche(2) << endl;
   cout << "ETAPE 18 : " << canevas->activerCouche(4) << endl;
   cout << "ETAPE 19 : " << endl;
   canevas->afficher(cout);
   cout << "ETAPE 20 : AIRE : " << canevas->aire() << endl;
   cout << "ETAPE 21 : " << canevas->reinitialiser() << endl;
   cout << "ETAPE 22 : " << endl;
   canevas->afficher(cout);
   cout << "ETAPE 23 : AIRE : " << canevas->aire() << endl;
   cout << "ETAPE 24 : " << canevas->activerCouche(3) << endl;
   cout << "ETAPE 24.1 : " << canevas->ajouterForme(new Carre(10,10,10)) << endl;
   cout << "ETAPE 24.2 : " << canevas->ajouterForme(nullptr) << endl;
   cout << "ETAPE 25 : " << canevas->activerCouche(6) << endl;
   cout << "ETAPE 26 : " << endl;
   canevas->afficher(cout);
   cout << "ETAPE 27 : AIRE : " << canevas->aire() << endl;
   
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.

    // [!!!] quoi??? tester quoi? ya rien dans les documents? - Zakary
}
