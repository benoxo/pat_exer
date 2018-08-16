#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    int A[25], B[25], i, len, HTable[10];
    char c;

    len = 0;
    memset(HTable, 0, sizeof(HTable));
    while (scanf("%c", &c) != EOF && isdigit(c)) {
        A[len++] = c - '0';
        HTable[c - '0']++;
    }

    memset(B, 0, sizeof(B));
    for (i = 0; i < len; i++) {
        B[i] += A[len - i - 1] * 2 % 10;
        B[i + 1] = A[len - i - 1] * 2 / 10;
        HTable[ B[i] ]--;
    }
    if (B[len] != 0) {
        HTable[ B[len] ]--;
        len++;
    }

    for (i = 0; i < 10; i++) {
        if (HTable[i] != 0) break;
    }
    if (i >= 10) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for (i = len; i > 0; i--) {
        printf("%d", B[i-1]);
    }

    return 0;
}
