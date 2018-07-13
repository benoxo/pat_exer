#include <stdio.h>

int main() {
    int A, B, D, sum;
    int extras[50], h;
    
    scanf("%d %d %d", &A, &B, &D);
    sum = A + B;
    h = 0;
    
    do {
        extras[h++] = sum % D;
        sum /= D;
    } while (sum > 0);
    
    while (h--) {
        printf("%d", extras[h]);
    }
    return 0;
}
