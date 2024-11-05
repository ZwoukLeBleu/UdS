/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 28 octobre 2023
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

#include <stdio.h>
//#include <string.h> 

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

struct MetaData meta = { "Domingo Palao", "2023-10-28", "Sherbrooke" };
struct MetaData meta2 = { "dwadwa", "213", "shebrook"};

int matrice[MAX_HAUTEUR][MAX_LARGEUR] = {{142, 0},{82, 255},{0, 55}};

struct RGB mat_color[MAX_HAUTEUR][MAX_LARGEUR] = {{0}};



int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
    FILE *pgm = NULL;
    pgm = fopen(nom_fichier, "r");
    if (pgm == NULL){
        return ERREUR_FICHIER;
        
    }
    printf("1\n");
    char fuckyou[50];
    size_t result_comment;
    result_comment += fscanf(pgm, "# %[^;];", p_metadonnees->auteur);
    //result_comment += fscanf(pgm, " %[^;];", fuckyou);
    result_comment += fscanf(pgm, " %[^;];", p_metadonnees->dateCreation);
    result_comment += fscanf(pgm, " %s", p_metadonnees->lieuCreation);

    if (result_comment != 3){
        //return ERREUR_FICHIER;
    }
    //strcat(p_metadonnees->auteur, fuckyou);
    printf("%s, %s, %s\n", p_metadonnees->auteur, p_metadonnees->dateCreation, p_metadonnees->lieuCreation);

    fscanf(pgm, "%s", fuckyou);
    if (fuckyou[0] != 'P' && fuckyou[1] != '2'){
        //return ERREUR_FORMAT;
    }
    fscanf(pgm, "%d %d", p_colonnes, p_lignes);
    if (*p_colonnes > MAX_HAUTEUR || *p_colonnes < 0 || *p_lignes > MAX_LARGEUR || *p_lignes < 0){
        return ERREUR_TAILLE;
    }
    fscanf(pgm, "%d", p_maxval);
    if (*p_maxval > MAX_VALEUR){ 
        return ERREUR_FORMAT; 
    }

    size_t result_data;
    for (int i = 0; i < *p_colonnes; i++){
        for (int j = 0; j < *p_lignes; j++){
            //printf("core\n");
            result_data += fscanf(pgm, "%d", &matrice[i][j]);
            //printf("%d\n", matrice[i][j]);
        }
        
        //result_data += fprintf(pgm, "\n");
    }
    if (result_data != *p_colonnes * *p_lignes)
    {
        printf("core\n");
        return ERREUR_FICHIER;
    }
    
    for (int i = 0; i < *p_colonnes; i++){
        for (int j = 0; j < *p_lignes; j++){
            printf("%d ", matrice[i][j]);
        }
        //printf("%d ", i);
        printf("\n");
        
    }

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
    size_t result_comment = fprintf(pgm, "# %s; %s; %s\n", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
    /*if (result_comment != ){ //return ERREUR_FICHIER;
        printf("%zd\n", sizeof(struct MetaData));
    printf("%zd\n", result_comment);
     }*/

    //headings
    size_t result_header = fprintf(pgm, "P2\n%d %d\n%d\n", colonnes, lignes, maxval);
    //if (result_header != )
    //printf("%zd\n", result_header);

    //image data (kinda raw)
    size_t result_data;
    for (int i = 0; i < colonnes; i++){
        for (int j = 0; j < lignes; j++){
            result_data += fprintf(pgm, "%d ", matrice[i][j]);
        }
        result_data += fprintf(pgm, "\n");

    }
    //printf("%zd\n", result_data);

    //if (result_data != lignes*colonnes){ return ERREUR_FICHIER; }

    fclose(pgm);
    return OK;
}



int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1]){
    if (histogramme == NULL){ return ERREUR; }
    else if (lignes < 0 || colonnes < 0 || lignes > MAX_LARGEUR || colonnes > MAX_HAUTEUR){ return ERREUR_TAILLE; }
    
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            histogramme[matrice[i][j]] += 1;
        }
    }
    return OK;
}


int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur){
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            matrice[i][j] = matrice[i][j] + valeur;
            if (matrice[i][j] > maxval){ matrice[i][j] = maxval; }
            if (matrice[i][j] < 0){ matrice[i][j] = 0; }
        }
    }
    

    return OK;
}

int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees){
    FILE *ppm = NULL;
    ppm = fopen(nom_fichier, "w");
    //metadata
    fprintf(ppm, "#%s; %s; %s\n", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
    //headings
    fprintf(ppm, "P3\n%d %d\n%d\n", colonnes, lignes, maxval);
    //image data (kinda raw)
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            fprintf(ppm, "%d %d %d ", matrice[i][j].valeurR, matrice[i][j].valeurG, matrice[i][j].valeurB);
        }
        fprintf(ppm, "\n");
    }
    fclose(ppm);
    return OK;
}



int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int *lignes3;
    int *colonnes3;
    int p_matrice[MAX_HAUTEUR][MAX_LARGEUR] = {{0}};

    //lignes3 = MAX_HAUTEUR;
    //colonnes3 = MAX_LARGEUR;

    int maxval = 255;
    int histogramme[MAX_VALEUR+1] = {0};
    char nom[MAX_CHAINE];
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

    pgm_ecrire("superidol.pgm", matrice, 2, 3, 255, meta);
    //printf("1");

    int test = pgm_lire("superidol.pgm", p_matrice, &lignes3, &colonnes3, &maxval, &metadonnees);
    printf("%d\n", test);
    //pgm_creer_histogramme(matrice, 2, 2, histogramme);

    ppm_ecrire("supercolor.ppm", mat_color, 256, 256, 255, meta2);

    printf("-> Fin!\n");

    return 0;
}



