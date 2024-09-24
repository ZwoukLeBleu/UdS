/*— complexité basse : recherche d’un caractère et détection de palindrome
  — complexité moyenne : calcul du sinus et calcul du cosinus à l’aide de séries
  — complexité haute : addition de matrices et multiplication de matrices carrées*/

#include <stdio.h>
#include "main.h"

#define MAX_SIN_N 10


struct matrixS {
        int n;
        int m;
        //matrix[99][99];
};
//typedef struct 

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

int power(int x, int p){
    int t = 1;
    for (p; p > 0; p--){
        t *= x;
    }
    return t;
}


//sin ~= x - x3/3! + x5/5!
//WIP
float sinNear(int x){
    float t = 0;
    for (int i = 1; i < 20; i+=2){
        //printf(" %d",i);
        t += power(-1,i)*(power(x,i)/factorial(i));
        printf(" %d",t);
    }
    return t;
    
}

/*void matrixAdd(struct matrixS m1, struct matrixS m2){
    if (m1.m == m2.m && m1.n == m2.n){
        struct matrixS m3 {m = }
        for (int i =0; i < m1.m; i++){
            for (int j =0; j < m1.n; i++){
                
            }
        }
        
    }
}*/

int main() {

   //struct test t1 = {1,2,'g'};
   //putchar(t1.c);
   //putchar(charFinder('E', greets));
    //char greets[] = "TENET";
    //int wt = palindromeCheck(greets, sizeof(greets));
    //printf("%d",wt);

    float test = sinNear(3);
    printf("%.6f", test);
    //int g = power(5,4);
    //printf("%d", g);

   printf("\n");
   return 0;
}

