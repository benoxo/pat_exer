#include <cstdio>
#include <cstring>

int main() {
    long long int N, R, num, cur, left, right;
    scanf("%lld", &N);
    R = 1, num = 0;
    while (N / R) {
        right = N % R;
        left = N / (R * 10);
        cur = N / R % 10;
        if (cur == 0) num += left * R;
        else if (cur == 1) num += left * R + right + 1;
        else if (cur > 1) num += (left + 1) * R;
        R *= 10;
    }
    printf("%lld", num);

    return 0;
}
