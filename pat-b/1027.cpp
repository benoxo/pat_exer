#include "stdio.h"

int main() {
    int N, i, j, S;
    char c;
    
    scanf("%d %c", &N, &c);
    S = 0;
    while (2*S*S - 1 <= N) S++;
    S -= 2;
    i = 0;
    while (i < S) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (j = 0; j < 2*(S-i)+1; j++) {
            printf("%c", c);
        }
        printf("\n");
        i++;
    }
    
    while (i >= 0) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (j = 0; j < 2*(S-i)+1; j++) {
            printf("%c", c);
        }
        printf("\n");
        i--;
    }
    S++;
    printf("%d", N - 2*S*S + 1);
    
    return 0;
} 
