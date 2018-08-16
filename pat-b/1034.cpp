#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll gcd(ll A, ll B) {
    if (B == 0) return A;
    else return gcd(B, A % B);
};

typedef struct {
    ll N, D;
} Fraction;

void Reduce(Fraction &F) {
    if (F.D < 0) {
        F.D *= -1;
        F.N *= -1;
    }
    ll C = gcd( abs(F.N), F.D );
    F.N /= C;
    F.D /= C;
};

void PrintFrac(Fraction F) {
    if (F.N < 0) printf("(");
    if (F.N % F.D == 0) {
        printf("%lld", F.N / F.D);
    } else if (abs(F.N) > F.D) {
        printf("%lld %lld/%lld", F.N / F.D, abs(F.N) % F.D, F.D);
    } else {
        printf("%lld/%lld", F.N, F.D);
    }
    if (F.N < 0) printf(")");
};

Fraction Add(Fraction F1, Fraction F2) {
    Fraction F;
    F.D = F1.D * F2.D;
    F.N = F1.D * F2.N + F2.D * F1.N;
    Reduce(F);
    return F;
};

Fraction Minus(Fraction F1, Fraction F2) {
    F2.N *= -1;
    return Add(F1, F2);
};

Fraction Multiply(Fraction F1, Fraction F2) {
    Fraction F;
    F.D = F1.D * F2.D;
    F.N = F1.N * F2.N;
    Reduce(F);
    return F;
};

Fraction Divide(Fraction F1, Fraction F2) {
    Fraction F;
    F.D = F1.D * F2.N;
    F.N = F1.N * F2.D;
    Reduce(F);
    return F;
};

int main() {
    Fraction A, B;
    scanf("%lld/%lld %lld/%lld", &A.N, &A.D, &B.N, &B.D);
    Reduce(A);
    Reduce(B);

    PrintFrac(A);
    printf(" + ");
    PrintFrac(B);
    printf(" = ");
    PrintFrac(Add(A, B));
    printf("\n");

    PrintFrac(A);
    printf(" - ");
    PrintFrac(B);
    printf(" = ");
    PrintFrac(Minus(A, B));
    printf("\n");

    PrintFrac(A);
    printf(" * ");
    PrintFrac(B);
    printf(" = ");
    PrintFrac(Multiply(A, B));
    printf("\n");

    PrintFrac(A);
    printf(" / ");
    PrintFrac(B);
    printf(" = ");
    if (B.N == 0) {
        printf("Inf");
    } else {
        PrintFrac(Divide(A, B));
    }
    printf("\n");

    return 0;
}
