#include "stdio.h"
#include "string.h"

int main() {
    char C;
    int S[200], i, lenA, max;
    
    memset(S, 0, sizeof(S));
    max = 0;
    while (scanf("%c", &C) != EOF) {
        if (C <= 'Z' && C >= 'A') C += 32;
        if (C <= 'z' && C >= 'a') {
            S[C]++;
            if (S[C] > max) {
                max = S[C];
            }
        }
    }
    
    for (i = 'a'; i <= 'z'; i++) {
        if (S[i] == max) {
            printf("%c %d", i, max);
            break;
        }
    }
    
    return 0;
}
