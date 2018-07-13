#include "stdio.h"

int main() {
    long long A, B, C;
    int count, i;
    
    scanf("%d", &count);
    for ( i = 0; i < count; i++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        if (A + B > C) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
