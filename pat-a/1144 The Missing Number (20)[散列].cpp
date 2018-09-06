#include <cstdio>
#include <cstring>
#define MAXN 100010

int Hash[MAXN];
int main() {
    int N, K;
    scanf("%d", &N);
    memset(Hash, 0, sizeof(Hash));
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        if (K < 0 || K >= MAXN) continue;
        Hash[K] = 1;
    }

    for (int i = 1; i < MAXN; i++) {
        if (Hash[i] == 0) {
            K = i;
            break;
        }
    }
    printf("%d\n", K);
    return 0;
}
