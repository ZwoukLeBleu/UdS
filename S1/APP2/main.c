/*— complexité basse : recherche d’un caractère et détection de palindrome
  — complexité moyenne : calcul du sinus et calcul du cosinus à l’aide de séries
  — complexité haute : addition de matrices et multiplication de matrices carrées*/

/*int main(){

    struct test {
        int a;
        int b;
        matrix[a][b];
    }
    return 0;
}*/
#include <stdio.h>
#include "main.h"

/*typedef int bool;
enum {
    false,
    true
};*/

struct test {
        int a;
        int b;
        char c;
};

// recherche d’un caractère 
//KINDA DONE
char charFind(char a, char str[]){
    int i;
    for (i = 0; i < sizeof(str); i++) {
        if (str[i] == a){
            return a;
        }
    }
}

//detection de palindrome
//WIP
int palindromeCheck(char str[], int p){
    
    if (str[p-1] == str[sizeof(str)-p]){
        return 1;
    }
    else return 0;
    
}



int main() {

   //struct test t1 = {1,2,'g'};
   //putchar(t1.c);
    
   //putchar(charFinder('E', greets));
    char greets[] = "TENET";
    int wt = palindromeCheck(greets, sizeof(greets));
    printf("%d",wt);

   printf("\n");
   return 0;
}

