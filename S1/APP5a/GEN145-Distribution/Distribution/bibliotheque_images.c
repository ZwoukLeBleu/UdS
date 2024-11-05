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

struct RGB mat_color[MAX_HAUTEUR][MAX_LARGEUR] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};



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
    //result_comment += fscanf(pgm, "# %[^;];", p_metadonnees->auteur);
    //result_comment += fscanf(pgm, " %[^;];", p_metadonnees->dateCreation);
    //result_comment += fscanf(pgm, " %s", p_metadonnees->lieuCreation);
    //result_comment += fscanf(pgm, " %[^;];", fuckyou);
    result_comment += fscanf(pgm, "# %[^;]; %[^;]; %s", p_metadonnees->auteur, p_metadonnees->dateCreation, p_metadonnees->lieuCreation);

    if (result_comment != 3){
        //return ERREUR_FICHIER;
        //printf("yooooo");
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
    for (int i = 0; i < *p_lignes; i++){
        for (int j = 0; j < *p_colonnes; j++){
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
    
    for (int i = 0; i < *p_lignes; i++){
        for (int j = 0; j < *p_colonnes; j++){
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
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
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
        int *p_tempLigne = p_lignes;
        p_lignes = p_colonnes;
        p_colonnes = p_lignes;
    }
    

    matrice = tempMatrice;


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

int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees){
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
    for (int i = 0; i < *p_lignes; i++){
        for (int j = 0; j < *p_colonnes; j++){
            //printf("core\n");
            result_data += fscanf(pgm, "%d %d %d ", &matrice[i][j].valeurR, &matrice[i][j].valeurG, &matrice[i][j].valeurB);
            //printf("%d\n", matrice[i][j]);
        }
        
        //result_data += fprintf(pgm, "\n");
    }
    if (result_data != *p_colonnes * *p_lignes)
    {
        printf("core\n");
        //return ERREUR_FICHIER;
    }
    
    for (int i = 0; i < *p_lignes; i++){
        for (int j = 0; j < *p_colonnes; j++){
            printf("%d %d %d ", matrice[i][j].valeurR, matrice[i][j].valeurG, matrice[i][j].valeurB);
        }
        //printf("%d ", i);
        printf("\n");
        
    }
    printf("\n\n");

    fclose(pgm);
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
            printf("%d %d %d ", matrice2[i][j].valeurR, matrice2[i][j].valeurG, matrice2[i][j].valeurB);
        }
    printf("\n");
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
    for(unsigned int i=0; i < *p_lignes; i++){
        for(unsigned int j = 0; j < *p_colonnes; j++){
            printf("%d %d %d ", matrice[i][j].valeurR, matrice[i][j].valeurG, matrice[i][j].valeurB);
        }
        printf("\n");
    }
    printf("\n");
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

    pgm_ecrire("superidol.pgm", matrice, 3, 2, 255, meta);
    //printf("1");

    int test = pgm_lire("superidol.pgm", p_matrice, &lignes3, &colonnes3, &maxval, &metadonnees);
    //printf("%d\n", test);
    //pgm_creer_histogramme(matrice, 2, 2, histogramme);

    //ppm_ecrire("supercolor.ppm", mat_color, 3, 3, 255, meta2);
    ppm_lire("supercolor.ppm", imageRGB1, &lignes1, &colonnes1, &maxval, &metadonnees);
    //ppm_copier(imageRGB1, 3, 3, imageRGB2, &lignes2, &colonnes2);
    ppm_pivoter90(imageRGB1, &lignes1, &colonnes1, 0);
    ppm_pivoter90(imageRGB1, &lignes1, &colonnes1, 0);
    ppm_pivoter90(imageRGB1, &lignes1, &colonnes1, 0);
    ppm_pivoter90(imageRGB1, &lignes1, &colonnes1, 0);


    printf("-> Fin!\n");

    return 0;
}



