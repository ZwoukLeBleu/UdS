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
struct MetaData meta2 = { "dwadwa", "213", "shebrook"};

int matrice[MAX_HAUTEUR][MAX_LARGEUR] = {{142, 3},{82, 255},{3, 55}};

struct RGB mat_color[MAX_HAUTEUR][MAX_LARGEUR] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int maxval;
    int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE];
    struct MetaData metadonnees;

	int retour;
    char nom_fichier[] = "/home/zwouklebleu/Documents/Prg/UdS/S1/APP5a/GEN145-Distribution/Distribution/Sherbrooke_Frontenac_nuit.pgm";

    printf("-> Debut!\n");

    pgm_lire(nom_fichier, image1, &lignes1, &colonnes1, &maxval, &meta);
    int test = pgm_extraire(image1, 50, 50, 175, 175, &lignes2, &colonnes2);
    pgm_ecrire("/home/zwouklebleu/Documents/Prg/UdS/S1/APP5a/GEN145-Distribution/Distribution/test.pgm", image1, lignes1, colonnes1, maxval, meta);
    /*ppm_lire(nom_fichier, imageRGB1, &lignes1, &colonnes1, &maxval, &meta);
    int test = ppm_pivoter90(imageRGB1, &lignes1, &colonnes1, SENS_ANTIHORAIRE);
    ppm_ecrire("/home/zwouklebleu/Documents/Prg/UdS/S1/APP5a/GEN145-Distribution/Distribution/test.ppm", imageRGB1, lignes1, colonnes1, maxval, meta);
*/
    printf("%d", test);

    printf("-> Fin!\n");

    return 0;
}
