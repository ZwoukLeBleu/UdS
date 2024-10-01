/********
Fichier: calculeSinusSerie
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/
#define MAX_TAYLOR_ITERATION 8
#define MAX_TAYLOR_EXPONENT 11
#define PI 3.14159265359

#include <stdio.h>


// Description  : calcule la factorielle d'un entier 
// Précondition : x est un entier positif
// Postcondition: t est un entier positif
int factorial(int x){
    if (x > 0){
        int t=1;
        for (x; x > 0; x--) {
            t *= x;
        }
        return t;
    }
    else { return -1; }
}

// Description  : calcule la puissance d'un nombre 
// Précondition : x est reel et p est un entier positif
// Postcondition: resultat du calcul (reel)
float power(float x, int p){
    float t = 1;
    for (p; p > 0; p--){
        t *= x;
    }
    return t;
}

// Description  : approxime la valeur du sinus d'un nombre
// Précondition : x doit etre entre -pi et pi
// Postcondition: total approximatif reel
float sinNear(float x){
    float t = 0;
    int i=1;
    for (int v = 1; v <= MAX_TAYLOR_ITERATION; v++){
        //printf(" %d",i);
        t += power(-1,v+1)*(power(x, i)/factorial(i));
        i += 2;
    }
    return t;
}

void sinNearTest(float x, float val){
    if (sinNear(x) >= val-0.001 && sinNear(x) <= val+0.001){
        printf("Resultat attendu de sin(%f) = %f --- Resultat obtenu = %f -> Test PASSED !\n", x,  val, sinNear(x));
    } else {
        printf("Resultat attendu de sin(%f) = %f --- Resultat obtenu = %f -> Test FAILED !\n", x,  val, sinNear(x));
    }
}

int main(){
    sinNearTest(1, 0.841471);
    sinNearTest(0, 0);
    sinNearTest(PI/4, 0.707107);    
    sinNearTest(PI/2, 1);
}