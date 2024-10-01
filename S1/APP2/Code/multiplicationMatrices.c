/********
Fichier: multiplicationMatrices
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

#include <stdio.h>
#define MATRIX1_M 3
#define MATRIX1_N 2
#define MATRIX2_M 2
#define MATRIX2_N 3
int mR[MATRIX1_M][MATRIX2_N] = {0};


// Description  : affiche une matrice à l'écran
// Précondition : matrice non-nulle
// Postcondition: N/A
void printMatrix(){
    for (int i = 0; i < MATRIX1_M; i++){
		printf("[");
        for (int j = 0; j < MATRIX2_N; j++){
            int x = mR[i][j];
            printf("%d ", x);
        }
		printf("]\n");
    }
}

// Description  : multiplie 2 matrices 
// Précondition : pour recevoir un resultat, le nombre de colonnes de la 1ere matrice doit etre egal au nombre de lignes de la 2eme matrice.
//                Les matrices doivent etre plus petites que MAX_MATRIX_SIZE 
// Postcondition: N/A
void matrixMul(int m1[MATRIX1_M][MATRIX1_N], int m2[MATRIX2_M][MATRIX2_N]){
	if(MATRIX1_N == MATRIX2_M){
        for (int i = 0; i <= MATRIX1_N; i++){
            for (int j = 0; j <= MATRIX1_M; j++){
                mR[i][j] = 0;
                for (int k = 0; k < MATRIX2_M; k++){
                    mR[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        printMatrix();
	}
	else {
		printf("Erreur");
}

int matrixEquality(int m1[MATRIX1_M][MATRIX2_N], int m2[MATRIX1_M][MATRIX2_N]) {
    for (int i = 0; i < MATRIX1_M; i++) {
        for (int j = 0; j < MATRIX1_M; j++) {
            if (m1[i][j] != m2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void matrixMulTest(int m1[MATRIX1_M][MATRIX2_N], int m2[MATRIX1_M][MATRIX2_N]) {
    if (matrixEquality(m1, m2) == 1) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
}

int main(){
    int m1[MATRIX1_M][MATRIX1_N] = {{1, 2}, {3, 4}, {5, 6}};
    int m2[MATRIX2_M][MATRIX2_N] = {{6,5,4}, {3,2,1}};
    int mT[MATRIX1_M][MATRIX2_N] = {{12, 9, 6}, {30, 23, 16}, {48, 37, 26}};
    
    matrixMul(m1, m2);
    matrixMulTest(mT, mR);
}
