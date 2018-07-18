#include "stdio.h"

int main() {
    long long P[3], pks, A[3], aks, ks;
    
    scanf("%lld.%lld.%lld %lld.%lld.%lld", P, P+1, P+2, A, A+1, A+2);
    
    pks = P[0]*17*29 + P[1]*29 + P[2];
    aks = A[0]*17*29 + A[1]*29 + A[2];
    ks = aks - pks;
    if (ks < 0) {
        printf("-");
        ks = -ks;
    }
    printf("%d.%d.%d", ks/29/17, ks/29%17, ks%29);
    
    return 0;
}
