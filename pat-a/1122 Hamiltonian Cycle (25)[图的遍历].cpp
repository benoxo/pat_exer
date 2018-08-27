#include <cstdio>
#include <cstring>
#define MAXN 210
#define MAXM 10010
#define INF 65535

int main() {
    int N, M, K, n, path[MAXM], Hash[MAXN], counter, V1, V2, G[MAXN][MAXN];

    memset(G[0], 0, sizeof(G));
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &V1, &V2);
        G[V1][V2] = G[V2][V1] = 1;
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &n);
        int j;
        for (j = 0; j < n; j++) {
            scanf("%d", path + j);
        }

        memset(Hash, false, sizeof(Hash));
        counter = N;
        if (n == N + 1) {
            for (j = 0; j < n-1; j++) {
                if (!G[ path[j] ][ path[j+1] ]) break;
                if (!Hash[ path[j] ]) {
                    Hash[ path[j] ] = true;
                    counter--;
                }
            }
        }

        if (counter > 0 || j < n-1 || path[n-1] != path[0]) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
