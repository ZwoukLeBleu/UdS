#include "formatif-fonctions.h"
#include  <string.h>
#include <stdio.h>


#define OK 1
#define ERREUR 0



// Lire un fichier selon le format indique
// parameters: 
//         fichier: le nom du fichier a traiter
//         tableauPrenomPopularite : le tableau avec les noms 
// return : 
//         1 : si tout se passe correctement
//         0 : s'il y a une erreur
int lireFichier(char fichier[],
struct PrenomPopularite tableauPrenomPopularite[]){
	FILE *file = NULL;
	file = fopen(fichier, "r");
	if (file == NULL) { return ERREUR; }
	
	//char test[100];
	int i = 0;
	while (feof(file) == 0){
		fscanf(file, "%s %s", tableauPrenomPopularite[i].prenom, tableauPrenomPopularite[i].popularite);
		printf("%s %s\n", tableauPrenomPopularite[i].prenom, tableauPrenomPopularite[i].popularite);
		//if () { break;}
		i++;
	}
	
	fclose(file);
	return OK;
	
}

// chercher votreNom dans les deux tableaux et affiche les messages
// parameters: 
//         tableauPrenomPopulariteGarcons : le tableau avec les noms des garcons
//         tableauPrenomPopulariteFilles : le tableau avec les noms des filles
//         votreNom : le nom a chercher
// return : 
//         1 : si tout se passe correctement
//         0 : s'il y a une erreur
int chercherNom(struct PrenomPopularite tableauPrenomPopulariteGarcons[],
struct PrenomPopularite tableauPrenomPopulariteFilles[], char votreNom[]){
		
		for (int i = 0;;i++){
			printf("A: %d, NOM: %s\n", i, tableauPrenomPopulariteGarcons[i].prenom);
			if (strcmp(votreNom, tableauPrenomPopulariteFilles[i].prenom) == 0 || strcmp(votreNom, tableauPrenomPopulariteGarcons[i].prenom) == 0){
				printf("%s!!!!", tableauPrenomPopulariteFilles[i].prenom);
				return OK;
				}
		}
		
		return ERREUR;

}

// Cherche votreNom dans un tableau et retourne la position dans un paramètre
// parameters: 
//         tableauPrenomPopularite : un tableau contenant les noms et la popularite
//         votreNom : le nom a chercher
//         position : la position dans le tableau ou se trouve le nom
// return : 
//         1 : si tout se passe correctement
//         0 : s'il y a une erreur
int chercherNomTableau(struct PrenomPopularite tableauPrenomPopularite[],
    char votreNom[], int* position){
			for (int i = 0;;i++){
			if (strcmp(votreNom, tableauPrenomPopularite[i].prenom)){
				*position = i;
				return OK;
				}
		}
		
		return ERREUR;

}

// Afficher le mesage lors que le nom a ete trouve
// parameters :
//         nom : le nom trouve
//         position : la position du nom
//         SEXE : le sexe du nom
//         popularite : la popularite du nom
// return :
//         aucun
void afficheMessageNomTrouve(char nom[], int position, char SEXE[],
    char popularite[]){
		printf("Nom trouve ! !\nNOM: %s\nPOSITION: %d\nSEXE: %s\nPOPULARITE: %s", nom, position, SEXE, popularite);
	}

//Afficher le message lors que le nom n'a pas ete trouve
// parameters :
//         nom : le nom non trouve
//         SEXE : le sexe du nom
void afficheMessageNomNonTrouve(char nom[], char SEXE[]){
	printf("fuck you");
}

//Creer le rapport de 5 noms plus populaires
// parameters : 
//         nomFIchier : le nom du fichier de sortie
//         sexe : le sexe du tableau
//         nombreElementsRapport : combien d'elements a afficher dans le rapport
//         tableauPrenomPopularite : le tableau de donnees
int creerRapport(char nomFichier[], char sexe[], int nombreElementsRapport,
struct PrenomPopularite tableauPrenomPopularite[]){
		return OK;

}
