#include "stdio.h"
#define INF 0x7fffffff

int main() {
    int N1, N2, i, j, index, A[200010], B, mid;

    scanf("%d", &N1);
    for (i = 0; i < N1; i++) {
        scanf("%d", A + i);
    }
    A[N1] = INF;
    scanf("%d", &N2);
    index = (N1 + N2 - 1) / 2;

    i = j = 0;
    for (j = 0; j < N2; j++) {
        scanf("%d", &B);
        while (i + j < index && i < N1 && A[i] <= B) {
            i++;
        }
        if (i + j == index) {
            mid = A[i] < B ? A[i] : B;
        }
    }
    if (i + j < index && j == N2) {
        mid = A[index - N2];
    }

    printf("%d\n", mid);
    return 0;
}
