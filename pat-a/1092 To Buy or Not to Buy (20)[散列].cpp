#include <cstdio>
#include <cstring>

int main() {
    char A[1010], B[1010];
    int S[200];
    int miss, i, lenA, lenB;
    fgets(A, 1010, stdin);
    fgets(B, 1010, stdin);
    
    memset(S, 0, sizeof(S));
    lenA = strlen(A);
    lenB = strlen(B);
    for (i = 0; i < lenA; i++) {
        S[ A[i] ]++;
    }
    miss = 0;
    for (i = 0; i < lenB; i++) {
        if (S[B[i]] > 0) {
            S[B[i]]--;
        } else {
            miss++;
        }
    }
    if (miss > 0) {
        printf("No %d", miss); 
    } else {
        printf("Yes %d", lenA - lenB);
    }
    
    return 0;
}
