#include "stdio.h"
#include "string.h"

int main() {
    int N, K, S[101], score;
    
    scanf("%d", &N);
    memset(S, 0, sizeof(S));
    while (N--) {
        scanf("%d", &score);
        S[score]++;
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &score);
        printf("%d", S[score]);
        if (K > 0) printf(" ");
    }
    return 0;
}
