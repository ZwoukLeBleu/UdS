/********
Fichier: nomDuFichier
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/
#define MAX_TAYLOR_I 10
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

// Description  : approxime la valeur du cosus d'un nombre
// Précondition : x doit etre entre -pi et pi
// Postcondition: total approximatif reel
// Description  : approxime la valeur du cocosus d'un nombre
// Précondition : x doit etre entre -pi et pi
// Postcondition: total approximatif reel
float cosNear(float x){
    float t = 0;
    int v=1;
    for (int i = 2; i < MAX_TAYLOR_I; i+=2){
        //printf(" %d",i);
        t += power(-1,v)*(power(x, i)/factorial(i));
        v++;
    }
    return t+1;
}

int main(){
    printf("%f\n", cosNear(1.0));
    printf("%f\n", cosNear(0.0));
    printf("%f\n", cosNear(PI/4));
    printf("%f\n", cosNear(PI/2));
}