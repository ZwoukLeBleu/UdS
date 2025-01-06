/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 28 octobre 2023
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

#include <stdio.h>

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
    FILE *pgm = NULL;
    pgm = fopen(nom_fichier, "r");
    if (pgm == NULL){
        printf("ERREUR_FICHIER\n");
        return ERREUR_FICHIER;
    }
    char format[50];
    size_t result_metadata = 0;
    result_metadata += fscanf(pgm, "# %[^;]; %[^;]; %s", p_metadonnees->auteur, p_metadonnees->dateCreation, p_metadonnees->lieuCreation);

    if (result_metadata != 3){
        return ERREUR_FICHIER;
    }

    fscanf(pgm, "%s", format);
    if (format[0] != 'P' && format[1] != '2'){
        return ERREUR_FORMAT;
    }
    fscanf(pgm, "%d %d", p_colonnes, p_lignes);
    if (*p_colonnes > MAX_HAUTEUR || *p_colonnes < 0 || *p_lignes > MAX_LARGEUR || *p_lignes < 0){
        return ERREUR_TAILLE;
    }
    fscanf(pgm, "%d", p_maxval);
    if (*p_maxval > MAX_VALEUR){ 
        return ERREUR_FORMAT; 
    }

    int result_data = 0;
    for (int i = 0; i < *p_lignes; i++){
        for (int j = 0; j < *p_colonnes; j++){
            fscanf(pgm, "%d", &matrice[i][j]);
            result_data += 1;
        }
    }
    if (result_data != (*p_colonnes) * (*p_lignes)){
        return ERREUR_FICHIER;
    }

    fclose(pgm);
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    if (colonnes > MAX_HAUTEUR || colonnes < 0 || lignes > MAX_LARGEUR || lignes < 0){
        return ERREUR_TAILLE;
    }
    
    FILE *pgm = NULL;
    pgm = fopen(nom_fichier, "w");
    //metadata
    fprintf(pgm, "# %s; %s; %s\n", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
    //headings
    fprintf(pgm, "P2\n%d %d\n%d\n", colonnes, lignes, maxval);
    //image data (kinda raw)
    int result_data = 0;
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            fprintf(pgm, "%d ", matrice[i][j]);
            result_data += 1;
        }
        fprintf(pgm, "\n");

    }
    fclose(pgm);
    return OK;
}

int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1]){
    if(lignes > MAX_HAUTEUR || lignes < 0){
        return ERREUR_TAILLE;
    }
    if(colonnes > MAX_LARGEUR || colonnes < 0){
        return ERREUR_TAILLE;
    }

    if (histogramme == NULL){ return ERREUR; }
    else if (lignes < 0 || colonnes < 0 || lignes > MAX_LARGEUR || colonnes > MAX_HAUTEUR){ return ERREUR_TAILLE; }
    
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            histogramme[matrice[i][j]] += 1;
        }
    }
    return OK;
}

int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes){
    if(lignes > MAX_HAUTEUR || lignes < 0){
        return ERREUR_TAILLE;
    }
    if(colonnes > MAX_LARGEUR || colonnes < 0){
        return ERREUR_TAILLE;
    }

    int histogramme[MAX_VALEUR+1] = {0};
    pgm_creer_histogramme(matrice, lignes, colonnes, histogramme);
    int max = 0;
    int colour = 0;
    for (int i = 0; i < MAX_VALEUR+1; i++){
        if (histogramme[i] > max){
            max = histogramme[i];
            colour = i;
        }
    }
    return colour;
}

int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur){
    if(lignes > MAX_HAUTEUR || lignes < 0){
        return ERREUR_TAILLE;
    }
    if(colonnes > MAX_LARGEUR || colonnes < 0){
        return ERREUR_TAILLE;
    }
    if(maxval > MAX_VALEUR || maxval < 0){
        return ERREUR_TAILLE;
    }
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            matrice[i][j] = matrice[i][j] + valeur;
            if (matrice[i][j] > maxval){ matrice[i][j] = maxval; }
            if (matrice[i][j] < 0){ matrice[i][j] = 0; }
        }
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
        for(unsigned int i = 0; i < *p_lignes; i++){
            for(unsigned int j = 0; j < *p_colonnes; j++){
                tempMatrice[j][i] = matrice[*p_lignes-1-i][j];
            }
        }
        int tempLigne = *p_lignes;
        *p_lignes = *p_colonnes;
        *p_colonnes = tempLigne;

        for(unsigned int i = 0; i < *p_lignes; i++){
            for(unsigned int j = 0; j < *p_colonnes; j++){
                matrice[i][j] = tempMatrice[i][j];
            }
        }
    }
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

    *p_colonnes = colonnes2 - colonnes1 + 1;
    *p_lignes = lignes2 - lignes1 + 1;

    for (unsigned int i = 0; i < *p_lignes; i++) {
        for (unsigned int j = 0; j < *p_colonnes; j++) {
            matrice[i][j] = matrice[lignes1 + i][colonnes1 + j];
        }
    }

    return OK;
}

    

int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees){
    FILE *ppm = NULL;
    ppm = fopen(nom_fichier, "r");
    if (ppm == NULL){
        return ERREUR_FICHIER;
        
    }
    char format[50];
    size_t result_metadata = 0;
    result_metadata += fscanf(ppm, "# %[^;]; %[^;]; %s", p_metadonnees->auteur, p_metadonnees->dateCreation, p_metadonnees->lieuCreation);

    if (result_metadata != 3){
        return ERREUR_FICHIER;
    }
    printf("%s, %s, %s\n", p_metadonnees->auteur, p_metadonnees->dateCreation, p_metadonnees->lieuCreation);

    fscanf(ppm, "%s", format);
    if (format[0] != 'P' && format[1] != '3'){
        return ERREUR_FORMAT;
    }
    fscanf(ppm, "%d %d", p_colonnes, p_lignes);
    if (*p_colonnes > MAX_HAUTEUR || *p_colonnes < 0 || *p_lignes > MAX_LARGEUR || *p_lignes < 0){
        return ERREUR_TAILLE;
    }
    fscanf(ppm, "%d", p_maxval);
    if (*p_maxval > MAX_VALEUR){ 
        return ERREUR_FORMAT; 
    }

    int result_data = 0;
    for (int i = 0; i < *p_lignes; i++){
        for (int j = 0; j < *p_colonnes; j++){
            fscanf(ppm, "%d %d %d ", &matrice[i][j].valeurR, &matrice[i][j].valeurG, &matrice[i][j].valeurB);
            result_data += 1;
        }
    }
    if (result_data != (*p_colonnes) * (*p_lignes)){
        return ERREUR_FICHIER;
    }
    
    fclose(ppm);
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


int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
    // Vérification des tailles de format
    if(lignes1 > MAX_HAUTEUR || lignes1 < 0){
        return ERREUR_TAILLE;
    }
    if(colonnes1 > MAX_LARGEUR || colonnes1 < 0){
        return ERREUR_TAILLE;
    }

    *p_lignes2 = lignes1;
    *p_colonnes2 = colonnes1;

    for(unsigned int i=0; i < lignes1; i++){
        for(unsigned int j = 0; j < colonnes1; j++){
            matrice2[i][j].valeurR = matrice1[i][j].valeurR;
            matrice2[i][j].valeurG = matrice1[i][j].valeurG;
            matrice2[i][j].valeurB = matrice1[i][j].valeurB;
        }
    }
    return OK;
}


int ppm_sont_identiques(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2){
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
            if(matrice1[i][j].valeurR != matrice2[i][j].valeurR || matrice1[i][j].valeurG != matrice2[i][j].valeurG || matrice1[i][j].valeurB != matrice2[i][j].valeurB){
                return ERREUR;
            }
        }
    }

    return OK;
}


int ppm_pivoter90(struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens){
    if(sens >SENS_HORAIRE || sens < SENS_ANTIHORAIRE){
        return ERREUR;
    }

    if(*p_colonnes > MAX_LARGEUR || *p_colonnes < 0){
        return ERREUR_TAILLE;
    }

    if(*p_lignes > MAX_HAUTEUR || *p_lignes < 0){
        return ERREUR_TAILLE;
    }

    struct RGB tempMatrice[MAX_HAUTEUR][MAX_LARGEUR] = {0};
    int iteration = 1;
    if(sens == SENS_ANTIHORAIRE){
        iteration = 3;
    }
    for(unsigned int s = 0; s < iteration; s++){
        for(unsigned int i = 0; i < *p_lignes; i++){
            for(unsigned int j = 0; j < *p_colonnes; j++){
                tempMatrice[j][i].valeurR = matrice[*p_lignes-1-i][j].valeurR;
                tempMatrice[j][i].valeurG = matrice[*p_lignes-1-i][j].valeurG;
                tempMatrice[j][i].valeurB = matrice[*p_lignes-1-i][j].valeurB;
            }
        }
        int tempLigne = *p_lignes;
        *p_lignes = *p_colonnes;
        *p_colonnes = tempLigne;

        for(unsigned int i = 0; i < *p_lignes; i++){
            for(unsigned int j = 0; j < *p_colonnes; j++){
                matrice[i][j].valeurR = tempMatrice[i][j].valeurR;
                matrice[i][j].valeurG = tempMatrice[i][j].valeurG;
                matrice[i][j].valeurB = tempMatrice[i][j].valeurB;
            }
        }
    }
    return OK;
}