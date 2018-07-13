#include "stdio.h"

int main() {
    int N, counter, gt;
    long long A, B, C, sum;
    
    scanf("%d", &N);
    counter = 1;
    while (N--) {
        scanf("%lld %lld %lld", &A, &B, &C);
        sum = A + B;
        if ( A < 0 && B < 0 && sum >= 0 ) gt = 0;
        else if ( A > 0 && B > 0 && sum <= 0) gt = 1;
        else if ( sum > C ) gt = 1;
        else gt = 0;
        printf("Case #%d: ", counter++);
        gt == 1 ? printf("true\n") : printf("false\n");
    }
    
    return 0;
} 
