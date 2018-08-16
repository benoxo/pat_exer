#include <cstdio>
#include <cstring>

int main() {
    int A[1010], B, i, Q[1010], R, j;
    char c;

    i = 0;
    while (scanf("%c", &c) && c != ' ') {
        A[i++] = c - '0';
    }
    scanf("%d", &B);

    j = 0;
    while (i--) {
        Q[j] = A[j] / B;
        A[j+1] += (A[j] % B) * 10;
        j++;
    }
    R = A[j-1] % B;

    i = 0;
    if (Q[0] == 0 && j > 1) i++;
    for (; i < j; i++) {
        printf("%d", Q[i]);
    }
    printf(" %d", R);

    return 0;
}
