/********
Fichier: detectionPalindrome
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

// Description  : vérifie si une chaine de caractères est un palindrome
// Précondition : i est l'index de départ et j est l'index de fin (habituelement 0 et strLength(str)-1)
// Postcondition: retourne 1 ou 0 tel qu'un bool
int palindromeCheck(char str[], int i, int j){
    if (i >= j) { return 1; } //return "TRUE" si les 2 'indexes' se croisent
    if (str[i]!=str[j]) { return 0; }
    return palindromeCheck(str, i+1, j-1);
}

void palindromeTest(char str[], int val){
    if (palindromeCheck(str, 0, strLength(str)-1) == val){
        printf("%s : Test passed\n", str);
    } else {
        printf("%s: Test failed\n", str);
    }
}

int main(){
    palindromeTest("racecar", 1);
    palindromeTest("gaming", 0);
    palindromeTest("KAYAK", 1);
}