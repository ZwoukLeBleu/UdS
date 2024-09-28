/********
Fichier: nomDuFichier
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

#include <stdio.h>
#include "main.h"

#define MAX_TAYLOR_I 10

// Description  : trouve l'index d'un caractère dans une chaine de caractères
// Précondition : 'a' est un caractère et 'str' est une chaine de caractères
// Postcondition: retourne l'index de 'a' si il est présent dans 'str', sinon retourne -1
int charFind(char a, char str[]){
    int i;
    for (i = 0; i < strLength(str); i++) {
        if (str[i] == a){
            return i;
        }
    }
    return -1;
}

// Description  : vérifie si une chaine de caractères est un palindrome
// Précondition : i est l'index de départ et j est l'index de fin (habituelement 0 et strLength(str)-1)
// Postcondition: retourne 1 ou 0 tel qu'un bool
int palindromeCheck(char str[], int i, int j){
    if (i >= j) { return 1; } //return "TRUE" si les 2 'indexes' se croisent
    if (str[i]!=str[j]) { return 0; }
    return palindromeCheck(str, i+1, j-1);
}

// Description  : donne la longueur d'une chaine de caractères
// Précondition : str se termine par '\0'
// Postcondition: i est un entier positif
int strLength(char *str){
    for(int i=0;;i++){
        if (str[i] == '\0'){
            //printf("%d", i);
            return i;
        }
    }
}

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
    int v=1;
    for (int i = 1; i < MAX_TAYLOR_I; i+=2){
        //printf(" %d",i);
        t += power(-1,v)*(power(x, i)/factorial(i));
        v++;
    }
    return t;
}

// Description  : approxime la valeur du cosinus d'un nombre
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

// Description  : affiche une matrice à l'écran
// Précondition : matrice non-nulle
// Postcondition: N/A
void printMatrix(Matrix m0){
    for (int i = 0; i < m0.m; i++){
        for (int j = 0; j < m0.n; j++){
            int x = m0.table[i][j];
            printf("%d ", x);
        }
    printf("\n");
    }
}

// Description  : additionne 2 matrices 
// Précondition : pour recevoir un resultat, les matrices doivent etre de meme taille
// Postcondition: N/A
void matrixAdd(Matrix m1, Matrix m2){
    if (m1.m == m2.m && m1.n == m2.n){
        Matrix mR = {m1.m, m1.n};
        for (int i = 0; i < m1.m; i++){
            for (int j = 0; j < m1.n; j++){
                mR.table[i][j] = m1.table[i][j] + m2.table[i][j];
            }
        }
    printMatrix(mR);
    }
    else{
        printf("Matrice(s) de mauvaise(s) taille(s)!");
    }
}

// Description  : multiplie 2 matrices 
// Précondition : pour recevoir un resultat, le nombre de colonnes de la 1ere matrice doit etre egal au nombre de lignes de la 2eme matrice
// Postcondition: N/A
void matrixMul(Matrix m1, Matrix m2){
    if (m1.n == m2.m){
        Matrix mR = {m1.m, m2.n};
        for (int i = 0; i < m1.m; i++){
            for (int j = 0; j < m1.n; j++){
                mR.table[i][j] = 0;
                for (int k = 0; k < m2.m; k++){
                    mR.table[i][j] += m1.table[i][k] * m2.table[k][j];
                }
            }
        }
        printMatrix(mR);
    }
    else{
        printf("Matrice(s) de mauvaise(s) taille(s)!");
    }
}

int main(){

    // char gaming[] = "RACECWAdfwahuofwajhfwajhbfwbjhhlaigkkkAR\0";
    // int wtf = palindromeRecur(gaming, 0, strLength(gaming)-1); 
    // int test = strLength(gaming);
    //printf("%i", test);

    Matrix m1 = {2, 2, {{1, 2}, {3, 4}}};
    Matrix m2 = {2, 2, {{5, 6}, {7, 8}}};
    matrixAdd(m1, m2);
    matrixMul(m1, m2);

    //float test = sinNear(2.8);
    //printf("%.6f", test);
    //printf("%d", power(-1,3));
    //int g = power(5,4);
    //printf("%d", g);

   printf("\n");
   return 0;
}

