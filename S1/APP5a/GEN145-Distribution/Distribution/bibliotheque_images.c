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


int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
    // Vérification des tailles de format
    if(lignes1 > MAX_HAUTEUR || lignes1 < 0){
        return ERREUR_TAILLE;
    }
    if(colonnes1 > MAX_LARGEUR || colonnes1 < 0){
        return ERREUR_TAILLE;
    }

    *p_lignes2 = lignes1;
    *p_colonnes2 = colonnes1;

    for(unsigned int i=0; i <= lignes1; i++){
        for(unsigned int j = 0; j <= colonnes1; j++){
            matrice2[i][j] = matrice1[i][j];
        }
    }
    return OK;
}

int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2){
    if(colonnes1 != colonnes2){
        return ERREUR_TAILLE;
    }

    if(lignes1 != lignes2){
        return ERREUR_TAILLE;
    }

    if(colonnes1 > MAX_LARGEUR || colonnes1 < 0){
        return ERREUR_TAILLE;
    }

    if(lignes1 > MAX_HAUTEUR || lignes1 < 0){
        return ERREUR_TAILLE;
    }

    if(colonnes2 > MAX_LARGEUR || colonnes2 < 0){
        return ERREUR_TAILLE;
    }

    if(lignes2 > MAX_HAUTEUR || lignes2 < 0){
        return ERREUR_TAILLE;
    }


    for(unsigned int i = 0; i <= lignes1; i++){
        for(unsigned int j = 0; j <= colonnes1; j++){
            if(matrice1[i][j] != matrice2[i][j]){
                return ERREUR;
            }
        }
    }

    return OK;

}

int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens){
    if(sens >SENS_HORAIRE || sens < SENS_ANTIHORAIRE){
        return ERREUR;
    }

    if(*p_colonnes > MAX_LARGEUR || *p_colonnes < 0){
        return ERREUR_TAILLE;
    }

    if(*p_lignes > MAX_HAUTEUR || *p_lignes < 0){
        return ERREUR_TAILLE;
    }

    int tempMatrice[MAX_HAUTEUR][MAX_LARGEUR] = {0};
    int iteration = 1;
    if(sens == SENS_ANTIHORAIRE){
        iteration = 3;
    }
    for(unsigned int s = 0; s < iteration; s++){
        for(unsigned int i = 0; i <= *p_lignes; i++){
        for(unsigned int j = 0; j <= *p_colonnes; j++){
            for(unsigned int k = 0; k <= *p_lignes; k++){
                tempMatrice[j][k] = matrice[i][j];
            }
        }
    }
    }
    

    matrice = tempMatrice;
    int *p_tempLigne = p_lignes;
    p_lignes = p_colonnes;
    p_colonnes = p_lignes;

    return OK;
}

int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval){
    if(maxval > MAX_VALEUR || maxval < 0){
        return ERREUR;
    }

    if(colonnes > MAX_LARGEUR || colonnes < 0){
        return ERREUR_TAILLE;
    }

    if(lignes > MAX_HAUTEUR || lignes < 0){
        return ERREUR_TAILLE;
    }

    for(unsigned int i = 0; i < lignes; i++){
        for(unsigned int j = 0; j < colonnes; j++){
            matrice[i][j] = maxval - matrice[i][j];
            if(matrice[i][j] < 0 ){
                matrice[i][j] = 0;
            }
        }
    }

    return OK;
    
}

int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes){
    if(colonnes1 > MAX_LARGEUR || colonnes1 < 0){
        return ERREUR_TAILLE;
    }

    if(lignes1 > MAX_HAUTEUR || lignes1 < 0){
        return ERREUR_TAILLE;
    }

    if(colonnes2 > MAX_LARGEUR || colonnes2 < 0){
        return ERREUR_TAILLE;
    }

    if(lignes2 > MAX_HAUTEUR || lignes2 < 0){
        return ERREUR_TAILLE;
    }

    if(lignes1 > lignes2) return ERREUR_TAILLE;

    if(colonnes1 > colonnes2) return ERREUR_TAILLE;

    *p_colonnes = colonnes2 - colonnes1;
    *p_lignes = lignes2 - lignes1;

    //int tempMatrice[MAX_HAUTEUR][MAX_LARGEUR] = {0};

    for(unsigned int i = lignes1; i < lignes2; i++){
        for(unsigned j = colonnes1; j < colonnes2; j++){
            //tempMatrice[i-lignes1][j-colonnes1] = matrice[i][j];
            matrice[i - lignes1][j - colonnes1] = matrice[i][j];
        }
    }
    //matrice = tempMatrice;
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



