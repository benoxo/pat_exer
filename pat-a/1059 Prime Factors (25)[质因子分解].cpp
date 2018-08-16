#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    int N, i, factor[100000], first, remain;
    scanf("%d", &N);
    memset(factor, 0, sizeof(factor));

    remain = N;
    i = 2;
    while (remain > 1) {
        while(remain % i == 0) {
            remain /= i;
            factor[i]++;
        }
        i++;
    }

    if (N == 1) {
        printf("1=1");
        return 0;
    }

    first = 1;
    printf("%d=", N);
    for (i = 0; i < 100000; i++) {
        if (factor[i]) {
            if (!first) printf("*");
            first = 0;
            printf("%d", i);
            if (factor[i] > 1) printf("^%d", factor[i]);
        }
    }
    return 0;
}
