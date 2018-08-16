#include <cstdio>
#include <cmath>

int main() {
    int N, i, cur, last, counter;
    scanf("%d", &N);
    counter = 0;
    last = 3;
    for (cur = 5; cur <= N; cur+=2) {
        for (i = 2; i <= sqrt(cur); i++) {
            if (cur % i == 0) break;
        }
        if (i > sqrt(cur)) {
            if (cur - last == 2) counter++;
            last = cur;
        }
    }
    printf("%d", counter);

    return 0;
}
