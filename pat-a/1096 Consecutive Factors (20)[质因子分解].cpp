#include <cstdio>
#include <cmath>

int main() {
    int N, MSize, i, remin, cend, begin, end;
    scanf("%d", &N);

    MSize = 0;
    for (i = 2; i <= sqrt(N); i++) {
        remin = N;
        cend = i;
        while (remin > 0 && remin % cend == 0) {
            remin /= cend;
            cend++;
        }
        if (cend - i > MSize) {
            MSize = cend - i;
            begin = i;
            end = cend;
        }
    }

    if (MSize == 0) {
        printf("1\n%d", N);
    } else {
        printf("%d\n", MSize);
        for (i = begin; i < end; i++) {
            if (i != begin) printf("*");
            printf("%d", i);
        }
    }

    return 0;
}
