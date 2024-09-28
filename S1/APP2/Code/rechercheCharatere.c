/********
Fichier: nomDuFichier
Auteurs: Zakary Romdhane romz6050
         Maïna Clermont clem5406
Date: 24/09/2024
Description: Fonctions qui font de l'aritmetique & des operations sur le matrices de base. Ne necessite pas d'input par l'utilisateur.
********/

#include <stdio.h>

// Description  : donne la longueur d'une chaine de caractères
// Précondition : str se termine par '\0'
// Postcondition: i est un entier positif
int strLength(char *str){
    for(int i=0;;i++){
        if (str[i] == '\0'){
            //printf("%d", i);
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

int main(){
    char anti[] = "anticonstitutionnellement";
    char bonjour[] = "bonjour";
    char allo[] = "allocommentcava";
    printf("%d\n", charFind('n', anti));
    printf("%d\n", charFind('e', bonjour));
    printf("%d\n", charFind('r', bonjour));
    printf("%d\n", charFind('a', allo));
}