#include "stdio.h"
#include "string.h"
#define MAX 1010

double A[MAX], B[MAX];

void PrintPoly(int item, int counter) {
    if (item == MAX) {
        printf("%d", counter);
        return;
    }
    if (A[item] + B[item] != 0) {
        counter++;
    } 
    PrintPoly(item+1, counter);
    if (A[item] + B[item] != 0) {
        printf(" %d %.1lf", item, A[item] + B[item]);
    } 
}

int main() {
    int Na, Nb, exp, i, counter;
    double coef;
    
    memset(A, 0, MAX*sizeof(double));
    memset(B, 0, MAX*sizeof(double));
    scanf("%d", &Na);
    for (i = 0; i < Na; i++) {
        scanf("%d %lf", &exp, &coef);
        A[exp] = coef;
    }
    scanf("%d", &Nb);
    for (i = 0; i < Nb; i++) {
        scanf("%d %lf", &exp, &coef);
        B[exp] = coef;
    }
    
    counter = 0;
    PrintPoly(0, counter);
    return 0;
}
