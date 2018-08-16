#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long int ll;

int ReverseWithRadix(int A, int D) {
    int base, B;
    base = 1, B = 0;
    while (A) {
        B = B * D + A % D;
        A /= D;
    }
    return B;
}

int IsPrime(int A) {
    int i;
    if (A <= 1) return 0;
    for (i = 2; i <= sqrt(A); i++) {
        if (A % i == 0) break;
    }
    if (i > sqrt(A)) return 1;
    else return 0;
}

int main() {
    int N, D;
    while (scanf("%d", &N) && N > 0) {
        scanf("%d", &D);
        if (IsPrime(N) && IsPrime(ReverseWithRadix(N, D))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
