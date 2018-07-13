#include "stdio.h"
#include "string.h"
#define MAX 1010

int main() {
    double A[MAX], C[2*MAX], coef, tcoef;
    int i, j, Na, Nb, exp, texp, counter;
    
    memset(A, 0, MAX*sizeof(double));
    memset(C, 0, 2*MAX*sizeof(double));
    scanf("%d", &Na);
    for (i = 0; i < Na; i++) {
        scanf("%d %lf", &exp, &coef);
        A[exp] = coef;
    }
    scanf("%d", &Nb);
    for (i = 0; i < Nb; i++) {
        scanf("%d %lf", &exp, &coef);
        for (j = 0; j < MAX; j++) {
            if (A[j] == 0) continue;
            texp = exp + j;
            tcoef = coef*A[j];
            C[texp] += tcoef;
        }
    }
    
    counter = 0;
    for (i = 0; i < 2*MAX; i++) {
        if (C[i] != 0) counter++;
    }
    
    printf("%d", counter);
    for (i = 2*MAX-1; i >= 0; i--) {
        if (C[i] != 0) {
            printf(" %d %.1lf", i, C[i]);
        }
    }
    return 0;
}
