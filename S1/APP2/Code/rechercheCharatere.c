/********
Fichier: rechercheCaractere
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions pour la recherche d'un caractère dans une chaîne de caractère
********/

#include <stdio.h>

// Description  : donne la longueur d'une chaine de caractères
// Précondition : str se termine par '\0'
// Postcondition: i est un entier positif
int strLength(char *str){
    for(int i=0;;i++){
        if (str[i] == '\0'){
            return i;
        }
    }
}

// Description  : trouve l'index d'un caractère dans une chaine de caractères
// Précondition : 'a' est un caractère et 'str' est une chaine de caractères
// Postcondition: retourne l'index de 'a' si il est présent dans 'str', sinon retourne -1
int charFind(char a, char str[]){
    int i;
    for (i = 0; i < strLength(str); i++) {
        if (str[i] == a){
            return i;
        }
    }
    return -1;
}

void charFindTest(char a, char str[], int val){
    if (charFind(a, str) == val){
		printf("'%c' est recherche dans %s. Le resultat attendu est %d.\n", a, str, val);
        printf("Resultat obtenu : %d -> Test passed !\n", charFind(a, str));
    } else {
		printf("'%c' est recherche dans %s. Le resultat attendu est %d.\n", a, str, val);
        printf("Resultat obtenu : %d -> Test failed !\n", charFind(a, str));
    }
}

int main(){
	char str1[] = "anticonstitutionnellement\0";
	char str2[] = "bonjour\0";
	char str3[] = "allocommentcava\0";
    charFindTest('n', str1, 1);
    charFindTest('e', str2, -1);
    charFindTest('r', str2, 6);
    charFindTest('a', str3, 0);
}
