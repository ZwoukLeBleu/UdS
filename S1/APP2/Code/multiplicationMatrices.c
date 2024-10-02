/********
Fichier: multiplicationMatrices
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

#include <stdio.h>
#define MATRIX_SIZE 3
int mR[MATRIX_SIZE][MATRIX_SIZE] = {0};


// Description  : affiche une matrice à l'écran
// Précondition : matrice non-nulle
// Postcondition: N/A
void printMatrix(int m0[MATRIX_SIZE][MATRIX_SIZE]){
    for (int i = 0; i < MATRIX_SIZE; i++){
		printf("[");
        for (int j = 0; j < MATRIX_SIZE; j++){
            int x = m0[i][j];
            printf("%d ", x);
        }
		printf("]\n");
    }
}

// Description  : multiplie 2 matrices 
// Précondition : m1 et m2 sont des matrices de taille 3x3
// Postcondition: N/A
void matrixMul(int m1[MATRIX_SIZE][MATRIX_SIZE], int m2[MATRIX_SIZE][MATRIX_SIZE]){
    for (int i = 0; i <= MATRIX_SIZE; i++){
        for (int j = 0; j <= MATRIX_SIZE; j++){
            mR[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++){
                mR[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int matrixEquality(int m1[MATRIX_SIZE][MATRIX_SIZE], int m2[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (m1[i][j] != m2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void matrixMulTest(int m1[MATRIX_SIZE][MATRIX_SIZE], int m2[MATRIX_SIZE][MATRIX_SIZE]) {
    if (matrixEquality(m1, m2) == 1) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
}

int main(){
    int m1[MATRIX_SIZE][MATRIX_SIZE] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int m2[MATRIX_SIZE][MATRIX_SIZE] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int mT[MATRIX_SIZE][MATRIX_SIZE] = {{30, 36, 42}, {66, 81, 96}, {102, 126, 150}};
    
    matrixMul(m1, m2); // modifie mR (global)
    
    printf("Matrice 1 :\n");
    printMatrix(m1);
    printf("\nMatrice 2 :\n");
    printMatrix(m2);
    printf("\nMatrice resultante attendu :\n");
    printMatrix(mT);
    printf("\nMatrice resultante obtenu :\n");
    printMatrix(mR);
    matrixMulTest(mT, mR);
}