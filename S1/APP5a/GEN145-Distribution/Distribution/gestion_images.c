/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 28 octobre 2023
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

struct MetaData meta = { "Domingo Palao", "2023-10-28", "Sherbrooke" };
struct MetaData meta2 = { "", " 213", "shebrok"};

int matrice[MAX_HAUTEUR][MAX_LARGEUR] = {{0, 1},{2, 3}};

int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int maxval;
    int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE];
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

    pgm_ecrire("superidol.pgm", matrice, 2, 2, 255, meta2);

    //pgm_creer_histogramme(matrice, 2, 2, histogramme);

    printf("-> Fin!\n");

    return 0;
}
