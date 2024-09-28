/********
Fichier: nomDuFichier
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

/*— complexité basse : recherche d’un caractère et détection de palindrome
  — complexité moyenne : calcul du sinus et calcul du cosinus à l’aide de séries
  — complexité haute : addition de matrices et multiplication de matrices carrées*/

#include <stdio.h>
#include "main.h"

#define MAX_TAYLOR_I 10
#define PI 3.141592

 //struct Matrix Matrix;

//typedef struct 

// recherche d’un caractère 
//DONE
int charFind(char a, char str[]){
    int i;
    for (i = 0; i < strLength(str); i++) {
        if (str[i] == a){
            return i;
        }
    }
    return -1;
}

//detection de palindrome
//DONE
int palindromeRecur(char str[], int i, int j){
    if (i >= j) { return 0; } //return "TRUE" si les 2 'indexes' se croisent
    if (str[i]!=str[j]) { return 1; }
    return palindromeRecur(str, i+1, j-1);
}

int strLength(char *str){
    for(int i=0;;i++){
        if (str[i] == '\0'){
            //printf("%d", i);
            return i;
        }
    }
}

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

float power(float x, int p){
    float t = 1;
    for (p; p > 0; p--){
        t *= x;
    }
    return t;
}

//sin ~= x - x3/3! + x5/5!
//ALMOST DONE, NOT OPTIMISED. RETURNS NEGATIVE OF EXPECTED ANSWER ?
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

//sin ~= 1 - x2/2! + x4/4!
//ALMOST DONE, NOT OPTIMISED. RETURNS NEGATIVE OF EXPECTED ANSWER ?
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

// Affiche matrix
void printMatrix(Matrix m0){
         for (int i = 0; i < m0.m; i++){
             for (int j = 0; j < m0.n; j++){
                      int x = m0.table[i][j];
                      printf("%d ", x);
             }
             printf("\n");
         }
}

// addition matrix
void matrixAdd(Matrix m1, Matrix m2){
         if (m1.m == m2.m && m1.n == m2.n){
                  Matrix mR;
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

// multiplication matrix
void matrixMul(Matrix m1, Matrix m2){
         if (m1.n == m2.m){
                  Matrix mR;
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

int main() {

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

