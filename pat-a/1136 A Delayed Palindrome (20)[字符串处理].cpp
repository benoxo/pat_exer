#include <cstdio>
#include <cstring>
#define MAXN 10010

void Add(char A[], char B[], char C[]) {
    int len = strlen(A);
    int carry = 0;
    int i;
    for (i = 0; i < len; i++) {
        C[i] = (A[len-i-1] + B[len-i-1] + carry - '0' - '0') % 10 + '0';
        carry = (A[len-i-1] + B[len-i-1] + carry - '0' - '0') / 10;
    }
    if (carry > 0) {
        C[i] = carry + '0';
        C[i+1] = 0;
    } else {
        C[i] = 0;
    }
}

bool IsPali(char A[]) {
    int len = strlen(A);
    int i;
    for (i = 0; i < len; i++) {
        if (A[i] != A[len-i-1]) {
            break;
        }
    }
    return i == len;
}

int main() {
    char N1[MAXN], N2[MAXN], Sum[MAXN];
    int len, slen, times;

    scanf("%s", N1);
    times = 0;
    while (times < 10 && !IsPali(N1)) {
        len = strlen(N1);
        for (int i = 0; i < len; i++) {
            N2[i] = N1[len-i-1];
        }
        N2[len] = 0;

        Add(N1, N2, Sum);
        slen = strlen(Sum);
        for (int i = 0; i < slen/2; i++) {
            char tmp = Sum[i];
            Sum[i] = Sum[slen-i-1];
            Sum[slen-i-1] = tmp;
        }
        printf("%s + %s = %s\n", N1, N2, Sum);
        memcpy(N1, Sum, sizeof(Sum));
        times++;
    }
    if (times >= 10) {
        printf("Not found in 10 iterations.\n");
    } else {
        printf("%s is a palindromic number.\n", N1);
    }

    return 0;
}
