#include "stdio.h"

int main() {
    int exp[1010], conf[1010], N, i;
    
    N = 0;
    while (scanf("%d%d", conf+N, exp+N) != EOF) N++;
    
    if (exp[N-1] == 0 && N == 1) {
        printf("0 0");
    } else {
        printf("%d %d", conf[0]*exp[0], exp[0]-1);
    }
    
    for (i = 1; i < N; i++) {
        if (exp[i] == 0) continue;
        printf(" %d %d", conf[i]*exp[i], exp[i]-1);
    }
    
    return 0;
}
