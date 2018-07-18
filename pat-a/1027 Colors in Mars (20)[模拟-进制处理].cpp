#include "stdio.h"

int main() {
    int A, N;
    char radix[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    
    N = 3;
    printf("#");
    while (N--) {
        scanf("%d", &A);    
        printf("%c%c", radix[A/13], radix[A%13]);
    }
    return 0;
}
