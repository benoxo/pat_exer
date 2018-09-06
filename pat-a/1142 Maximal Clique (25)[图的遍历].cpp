#include <cstdio>
#include <vector>
#include <cstring>
#include <vector>
#define MAXN 210
using namespace std;

int G[MAXN][MAXN];
int query[MAXN];
int Nv, Ne, M, K;

void Judge() {
    bool IsMax, IsClique;
    IsMax = IsClique = true;
    for (int i = 0; i < K; i++) {
        int V1 = query[i];
        for (int j = i+1; j < K; j++) {
            int V2 = query[j];
            if (G[V1][V2] == 0) {
                IsClique = false;
            }
        }
        if (!IsClique) break;
    }

    int Hash[MAXN];
    memset(Hash, true, sizeof(Hash));
    for (int i = 0; i < K; i++) {
        Hash[ query[i] ] = false;
    }
    for (int i = 1; i <= Nv; i++) {
        if (!Hash[i]) continue;
        int V = i;
        int MoreOne = true;
        for (int j = 0; j < K; j++) {
            if (G[V][ query[j] ] != 1) {
                MoreOne = false;
            }
        }

        if (MoreOne) {
            IsMax = false;
            break;
        }
    }

    if (IsClique && IsMax) {
        printf("Yes\n");
    } else if (IsClique) {
        printf("Not Maximal\n");
    } else {
        printf("Not a Clique\n");
    }
}

int main() {
    int V1, V2;

    memset(G[0], 0, sizeof(G));
    scanf("%d %d", &Nv, &Ne);
    for (int i = 0; i < Ne; i++) {
        scanf("%d %d", &V1, &V2);
        G[V1][V2] = G[V2][V1] = 1;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", query + j);
        }

        Judge();
    }

    return 0;
}
