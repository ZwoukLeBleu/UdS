/*— complexité basse : recherche d’un caractère et détection de palindrome
  — complexité moyenne : calcul du sinus et calcul du cosinus à l’aide de séries
  — complexité haute : addition de matrices et multiplication de matrices carrées*/

#include <stdio.h>
#include "main.h"

#define MAX_SIN_N 3

/*typedef int bool;
enum {
    false,
    true
};*/

struct matrixS {
        int n;
        int m;
        matrix[99][99];
};

// recherche d’un caractère 
//KINDA DONE
int charFind(char a, char str[]){
    int i;
    for (i = 0; i < sizeof(str); i++) {
        if (str[i] == a){
            return i;
        }
    }
    return -1;
}

//detection de palindrome
//WIP
int palindromeCheck(char str[], int p){
    
    if (str[p-1] == str[sizeof(str)-p]){
        return 1;   
    }
    else return 0;
    
}

int factorial(int x){
    if (x > 0){
        int t=1;
        for (x; x > 0; x--) {
            t *= x;
        }
        return t;
    }
    else { return -1; }
    
}

//sin ~= x - x3/3! + x5/5!
//WIP
float sinNear(int x){
    int i;
    int t = 0;
    for (i = 0; i < MAX_SIN_N; i+2){
        t += ((-1)^(i))*((x^i)/factorial(i));
    }
}

int matrixAdd(){

}


int main() {

   //struct test t1 = {1,2,'g'};
   //putchar(t1.c);
    
   //putchar(charFinder('E', greets));
    //char greets[] = "TENET";
    //int wt = palindromeCheck(greets, sizeof(greets));
    //printf("%d",wt);

    float test = sinNear(3);
    printf("%.6f", test);
    //printf("%d", test);

   printf("\n");
   return 0;
}

