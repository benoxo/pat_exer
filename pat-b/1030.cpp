#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int N, i, j, A[100010], len;
    long long int p;

    scanf("%d %lld", &N, &p);
    for (i = 0; i < N; i++) {
        scanf("%d", A + i);
    }
    sort(A, A + N);
    len = 0;
    for (i = 0; i < N; i++) {
        j = upper_bound(A + i + 1, A + N, A[i] * p) - A;
        if (j - i > len) {
            len = j - i;
        }
    }
    printf("%d", len);
    return 0;
}
