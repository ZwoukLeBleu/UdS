/*— complexité basse : recherche d’un caractère et détection de palindrome
  — complexité moyenne : calcul du sinus et calcul du cosinus à l’aide de séries
  — complexité haute : addition de matrices et multiplication de matrices carrées*/

#include <stdio.h>
#include "main.h"

#define MAX_TAYLOR_I 10


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
    for (i = 0; i < sizeof(str); i++) { //TODO: fix gcc qui chialle sur sizeof(char[])
        if (str[i] == a){
            return i;
        }
    }
    return -1;
}



//detection de palindrome
//DONE
int palindromeRecur(char string[], int i, int j){
    if (i >= j) { return 0; } //return TRUE si les 2 'indexes' se croisent
    if (string[i]!=string[j]) { return 1; }
    return palindromeRecur(string, i+1, j-1);
    
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

float power(float x, int p){
    float t = 1;
    for (p; p > 0; p--){
        t *= x;
    }
    return t;
}


//sin ~= x - x3/3! + x5/5!
//DONE, NOT OPTIMISED
float sinNear(float x){
    float t = 0;
    int v=1;
    for (int i = 1; i < MAX_TAYLOR_I; i+=2){
        //printf(" %d",i);
        t += power(-1,v)*(power(x, i)/factorial(i));
        v++;
    }
    return t;
}


//sin ~= 1 - x2/2! + x4/5!
//DONE, NOT OPTIMISED
float cosNear(float x){
    float t = 0;
    int v=1;
    for (int i = 2; i < MAX_TAYLOR_I; i+=2){
        //printf(" %d",i);
        t += power(-1,v)*(power(x, i)/factorial(i));
        v++;
    }
    return t+1;
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

    char gaming[] = "RACECAR";
    int wtf = palindromeRecur(gaming, 0, 7-1); 
    //printf("%d",wtf);

    float test = sinNear(3);
    printf("%.6f", test);
    //printf("%d", power(-1,3));
    //int g = power(5,4);
    //printf("%d", g);

   printf("\n");
   return 0;
}

