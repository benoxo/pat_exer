#include <cstdio>
#include <algorithm>
typedef long long int ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

typedef struct {
    ll N, D;
} Fraction;

int Add(Fraction *A, Fraction *B) {
    A->N = A->N * B->D + B->N * A->D;
    A->D = A->D * B->D;
    ll C = gcd(abs(A->D), abs(A->N));
    if (C) {
        A->D /= C;
        A->N /= C;
    }
    return 0;
};

void PrintFrac(Fraction A) {
    if (A.N % A.D == 0) {
        printf("%lld", A.N/A.D);
    } else if (A.N > A.D) {
        printf("%lld %lld/%lld", A.N/A.D, abs(A.N)%A.D, A.D);
    } else {
        printf("%lld/%lld", A.N%A.D, A.D);
    }
}

int main() {
    int N, i;
    Fraction F1, sum;
    scanf("%d", &N);
    sum.D = 1, sum.N = 0;
    for (i = 0; i < N; i++) {
        scanf("%lld/%lld", &F1.N, &F1.D);
        Add(&sum, &F1);
    }
    PrintFrac(sum);
    return 0;
}
