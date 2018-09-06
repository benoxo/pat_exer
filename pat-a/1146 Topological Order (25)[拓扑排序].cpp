#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define MAXN 1010
using namespace std;

int G[MAXN][MAXN];
int GT[MAXN][MAXN];
int N, M, K, V1, V2, query[MAXN];
vector<int> Not;

bool IsTopological() {
    memcpy(GT[0], G[0], sizeof(G));
    for (int i = 0; i < N; i++) {
        int V = query[i];
        for (int W = 1; W <= N; W++) {
            if (GT[W][V] == 1) {
                return false;
            }
            GT[V][W] = 0;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &M);

    memset(G[0], 0, sizeof(G));
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &V1, &V2);
        G[V1][V2] = 1;
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", query + j);
        }

        if(!IsTopological()) {
            Not.push_back(i);
        }
    }

    for (int i = 0; i < Not.size(); i++) {
        printf("%d", Not[i]);
        if (i < Not.size() - 1) printf(" ");
    }

    return 0;
}
