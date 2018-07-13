#include <stdio.h>

int main() {
    int N, count;
    
    count = 0;
    scanf("%d", &N);
    while (N > 1) {
        if (N % 2) {
            N = (3*N + 1)/2;
        } else {
            N /= 2;
        }
        count++;
    }
    
    printf("%d\n", count);
    return 0;
} 
