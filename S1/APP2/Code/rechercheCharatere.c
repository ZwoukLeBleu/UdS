/********
Fichier: rechercheCaractere
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

charFindTest(char a, char str[], int val){
    if (charFind(a, str) == val){
        printf("%c in %s at i=%d : Test passed\n", a, str, val);
    } else {
        printf("%c in %s at i= %d : Test failed\n", a, str, val);
    }
}

int main(){
    charFindTest('a', "racecar", 1);
    charFindTest('g', "gaming", 0);
    charFindTest('w', "ALLO", -1);
    charFindTest('Y', "salutAvecUnY", 11);
}
