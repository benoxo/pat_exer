#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int IsPrime(int A) {
    if (A < 2) return 0;
    int i;
    for (i = 2; i <= sqrt(A); i++) {
        if (A % i == 0) return 0;
    }
    return 1;
}

int Hash(int A, int N) {
    return A % N;
}

int main() {
    int N, MSize, HTable[100000], i, A, Pos, j;
    scanf("%d %d", &MSize, &N);
    while (!IsPrime(MSize)) {
        MSize++;
    }
    memset(HTable, 0, sizeof(HTable));

    for (i = 0; i < N; i++) {
        scanf("%d", &A);
        Pos = Hash(A, MSize);
        for (j = 1; j <= MSize; j++) {
            if (HTable[Pos] == 0) {
                HTable[Pos] = A;
                printf("%d", Pos);
                break;
            }
            Pos = (Pos + 2 * j - 1) % MSize;
        }
        if (j > MSize) printf("-");
        if (i < N-1) printf(" ");
    }
    return 0;
}
