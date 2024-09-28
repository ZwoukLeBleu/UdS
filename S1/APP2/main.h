#ifndef MYHEADER_H
#define MYHEADER_H

typedef struct Matrix {
        int n;
        int m;
        int table[99][99];
} Matrix;

int charFind(char a, char str[]);
int palindromeCheck(char str[], int i, int j);
int strLength(char str[]);
int factorial(int x);
float power(float x, int p);
float sinNear(float x);
void matrixAdd(Matrix m1, Matrix m2);
void matrixMul(Matrix m1, Matrix m2);

#endif