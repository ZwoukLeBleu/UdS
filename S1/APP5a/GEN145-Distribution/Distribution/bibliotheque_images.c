/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 28 octobre 2023
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

#include <stdio.h>

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

struct MetaData meta = { "Domingo Palao", "2023-10-28", "Sherbrooke" };
struct MetaData meta2 = { "", " 213", "shebrok"};

int matrice[MAX_HAUTEUR][MAX_LARGEUR] = {{0, 1},{2, 8}};


int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
    FILE *pgm = NULL;
    pgm = fopen(nom_fichier, "r");
    if (pgm == NULL){
        return ERREUR_FICHIER;
        
    }

     size_t len = 0;
    //ssize_t read;
    char * line = NULL;
    /*while ((read = getline(&line, &len, pgm)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }*/

    fclose(pgm);
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    FILE *pgm = NULL;
    pgm = fopen(nom_fichier, "w");

    //metadata
    fprintf(pgm, "#%s; %s; %s\n", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
    //headings
    fprintf(pgm, "P2\n%d %d\n%d\n", colonnes, lignes, maxval);
    //image data (kinda raw)
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            fprintf(pgm, "%d ", matrice[i][j]);
        }
        fprintf(pgm, "\n");
    }
    fclose(pgm);
    return OK;
}



int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1]){
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            histogramme[matrice[i][j]] += 1;
        }
    }
    for (int k = 0; k <= 255; k++){
        printf("NBR DE %d: %d\n", k, histogramme[k]);
    }
    return OK;
}

int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int maxval;
    int histogramme[MAX_VALEUR+1] = {0};
    char nom[MAX_CHAINE];
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

    //pgm_ecrire("superidol.pgm", matrice, 2, 2, 255, meta2);

    pgm_creer_histogramme(matrice, 2, 2, histogramme);

    printf("-> Fin!\n");

    return 0;
}



