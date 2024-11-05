/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 28 octobre 2023
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"



/*int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

struct MetaData meta = { "Domingo Palao", "2023-10-28", "Sherbrooke" };
struct MetaData meta2 = { "", " 213", "shebrok"};*/

//int matrice[MAX_HAUTEUR][MAX_LARGEUR] = {{0, 1},{2, 3}};

void showMatrice(int m[10][10], int lignes, int colonnes){
     for(unsigned int i = 0; i < lignes; i++){
        printf("[ ");
        for(unsigned int j = 0; j < colonnes; j++){
            printf("%d ", m[i][j]);
        }
        printf("]\n");
     }
}

void transpose(int m[10][10], int *p_lignes, int *p_colonnes, int sens){
    int tempMatrice[10][10] = {0};
    int iteration = 1;
    if(sens == SENS_ANTIHORAIRE){
        iteration = 3;
    }
    for(unsigned int s = 0; s < iteration; s++){
        for(unsigned int i = 0; i < *p_lignes; i++){
            for(unsigned int j = 0; j < *p_colonnes; j++){
                tempMatrice[j][i] = m[*p_lignes-1-i][j];
            }
        }
        int tempLigne = *p_lignes;
        *p_lignes = *p_colonnes;
        *p_colonnes = tempLigne;

        for(unsigned int i = 0; i < *p_lignes; i++){
            for(unsigned int j = 0; j < *p_colonnes; j++){
                m[i][j] = tempMatrice[i][j];
            }
        }

    }
    
}


int main()
{
    /*int lignes1, colonnes1;
    int lignes2, colonnes2;
    int maxval;
    int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE];
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

    pgm_ecrire("superidol.pgm", matrice, 2, 2, 255, meta2);

    //pgm_creer_histogramme(matrice, 2, 2, histogramme);

    printf("-> Fin!\n");*/

    int l = 3;
    int c = 2;
    int mat[10][10] = {0};

    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;
    mat[2][0] = 5;
    mat[2][1] = 6;

    showMatrice(mat, l, c);
    transpose(mat, &l, &c, SENS_ANTIHORAIRE);
    showMatrice(mat, l, c);

    return 0;
}
