/********
Fichier: additionMatrices
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

#include <stdio.h>

#define MAX_MATRIX_SIZE 99

/*typedef struct Matrix {
        int m;
        int n;
        int table[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
} Matrix;*/

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
//                Les matrices doivent etre plus petites que MAX_MATRIX_SIZE 
// Postcondition: N/A
Matrix matrixAdd(Matrix m1, Matrix m2){
    if (m1.m == m2.m && m1.n == m2.n){
        Matrix mR = {m1.m, m1.n};
        for (int i = 0; i <= m1.m; i++){
            for (int j = 0; j <= m1.n; j++){
                mR.table[i][j] = m1.table[i][j] + m2.table[i][j];
            }
        }
        return mR;
    //printMatrix(mR);
    }
    else{
        return m1;
        //printf("Matrice(s) de mauvaise(s) taille(s)!");
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

void matrixAddTest(Matrix m1, Matrix m2, Matrix mR){
    if (matrixEquality(matrixAdd(m1, m2), mR) == 1){
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }

}

int main(){
    Matrix m1 = {3, 2, {{1, 2}, {3, 4}, {5, 6}}};
    Matrix m2 = {3, 2, {{6,5}, {4,3}, {2,1}}};
    Matrix mR = {3, 2, {{7, 7}, {7, 7}, {7, 7}}};

    matrixAddTest(m1, m2, mR);
}
