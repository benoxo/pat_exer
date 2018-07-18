#include "stdio.h"

int main() {
    int N, a, b, c, i;
    
    scanf("%d", &N);
    a = N % 10;
    b = N / 10 % 10;
    c = N / 100;
    
    for (i = 0; i < c; i++) {
        printf("B");
    }
    for (i = 0; i < b; i++) {
        printf("S");
    }
    for (i = 0; i < a; i++) {
        printf("%d", i+1);
    }
    return 0;
} 
