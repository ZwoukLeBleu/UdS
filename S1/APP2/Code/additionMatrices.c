/********
Fichier: additionMatrices
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

#include <stdio.h>

#define MAX_MATRIX_SIZE 99
#define MATRIX1_M 2
#define MATRIX1_N 3
#define MATRIX2_M 2
#define MATRIX2_N 3
int mR[MATRIX1_M][MATRIX1_N] = {0};

// Description  : affiche une matrice à l'écran
// Précondition : matrice non-nulle
// Postcondition: N/A
void printMatrix(int m0[MATRIX1_M][MATRIX1_N]){
    for (int i = 0; i < MATRIX1_M; i++){
        printf("[");
        for (int j = 0; j < MATRIX1_N; j++){
            int x = m0[i][j];
            printf("%d ", x);
        }
		printf("]\n");
    }
}

// Description  : additionne 2 matrices 
// Précondition : pour recevoir un resultat, les matrices doivent etre de meme taille
//                Les matrices doivent etre plus petites que MAX_MATRIX_SIZE 
// Postcondition: N/A
void matrixAdd(int m1[MATRIX1_M][MATRIX1_N], int m2[MATRIX2_M][MATRIX2_N]){
    if (MATRIX1_M == MATRIX2_M && MATRIX1_N ==  MATRIX2_N){
        for (int i = 0; i <= MATRIX1_M; i++){
            for (int j = 0; j <= MATRIX1_N; j++){
                mR[i][j] = m1[i][j] + m2[i][j];
            }
        }
    //printMatrix(mR);
    }
    else{
        //printf("Matrice(s) de mauvaise(s) taille(s)!");
    }
}

int matrixEquality(int m1[MATRIX1_M][MATRIX1_N], int m2[MATRIX1_M][MATRIX1_N]) {
    for (int i = 0; i < MATRIX1_M; i++) {
        for (int j = 0; j < MATRIX1_N; j++) {
            if (m1[i][j] != m2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void matrixAddTest(int m1[MATRIX1_M][MATRIX2_N], int m2[MATRIX1_M][MATRIX2_N]) {
    if (matrixEquality(m1, m2) == 1) {
        printf("\nTest passed\n");
    } else {
        printf("\nTest failed\n");
    }
}

int main(){
    int m1[MATRIX1_M][MATRIX1_N] = {{1,2,3}, {4,5,6}};
    int m2[MATRIX2_M][MATRIX2_N] = {{6,5,4}, {3,2,1}};
    int mT[MATRIX1_M][MATRIX2_N] = {{7,7,7}, {7,7,7}};
    
    matrixAdd(m1, m2); // modifie mR (global)

    printf("Matrice 1 :\n");
    printMatrix(m1);
    printf("\nMatrice 2 :\n");
    printMatrix(m2);
    printf("\nMatrice resultante attendu :\n");
    printMatrix(mT);
    printf("\nMatrice resultante obtenu :\n");
    printMatrix(mR);
    matrixAddTest(mT, mR);

    return 0;

}
