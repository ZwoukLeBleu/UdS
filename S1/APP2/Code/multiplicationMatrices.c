/********
Fichier: nomDuFichier
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

#include <stdio.h>
#define MAX_MATRIX_SIZE 99

typedef struct Matrix {
        int n;
        int m;
        int table[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
} Matrix;

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

// Description  : multiplie 2 matrices 
// Précondition : pour recevoir un resultat, le nombre de colonnes de la 1ere matrice doit etre egal au nombre de lignes de la 2eme matrice.
//                Les matrices doivent etre plus petites que MAX_MATRIX_SIZE 
// Postcondition: N/A
Matrix matrixMul(Matrix m1, Matrix m2){
    if (m1.n == m2.m){
        Matrix mR = {m1.n, m2.m};
        for (int i = 0; i <= m1.m; i++){
            for (int j = 0; j <= m1.n; j++){
                mR.table[i][j] = 0;
                for (int k = 0; k <= m2.m; k++){
                    mR.table[i][j] += m1.table[i][k] * m2.table[k][j];
                }
            }
        }
        return mR;
    }
    else{
        return m1;
    }
}

int matrixEquality(Matrix m1, Matrix m2){
    if (m1.m == m2.m && m1.n == m2.n){
        for (int i = 0; i <= m1.m; i++){
            for (int j = 0; j <= m1.n; j++){
                if (m1.table[i][j] != m2.table[i][j]){
                    return 0;
                }
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

void matrixMulTest(Matrix m1, Matrix m2, Matrix mR){
    if (matrixEquality(matrixMul(m1, m2), mR) == 1){
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
}

int main(){
    Matrix m1 = {3, 2, {{1, 2}, {3, 4}, {5, 6}}};
    Matrix m2 = {2, 3, {{6,5,4}, {3,2,1}}};
    Matrix mR = {3, 3, {{12, 9, 6}, {30, 23, 16}, {48, 37, 26}}};
    matrixMulTest(m1, m2, mR);

}
