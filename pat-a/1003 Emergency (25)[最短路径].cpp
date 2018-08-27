#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 510
#define INFINITY 65535
using namespace std;

int N, M, C1, C2, teams[MAXN];
int G[MAXN][MAXN], PathNum[MAXN], collected[MAXN], dist[MAXN], Weight[MAXN];

void InitG() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            G[i][j] = INFINITY;
        }
    }
}

int FindMindist(int V) {
    int Mindist = INFINITY;
    int S = -1;
    for (int i = 0; i < MAXN; i++) {
        if (!collected[i] && dist[i] < Mindist) {
            Mindist = dist[i];
            S = i;
        }
    }
    return S;
}

void Dijkstra() {
    memset(collected, 0, sizeof(collected));
    fill(dist, dist + MAXN, INFINITY);
    dist[C1] = 0;
    PathNum[C1] = 1;
    Weight[C1] = teams[C1];

    while (true) {
        int V = FindMindist(C1);
        if (V == -1) break;

        collected[V] = true;
        for (int W = 0; W < MAXN; W++) {
            if (!collected[W] && G[V][W] < INFINITY) {
                if (dist[V] + G[V][W] < dist[W]) {
                    dist[W] = dist[V] + G[V][W];
                    Weight[W] = Weight[V] + teams[W];
                    PathNum[W] = PathNum[V];
                } else if (dist[V] + G[V][W] == dist[W]) {
                    if (Weight[V] + teams[W] > Weight[W]) {
                        Weight[W] = Weight[V] + teams[W];
                    }
                    PathNum[W] += PathNum[V];
                }
            }
        }
    }
}

int main() {
    int Ca, Cb, L;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);

    for (int i = 0; i < N; i++) {
        scanf("%d", teams + i);
    }

    InitG();
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &Ca, &Cb, &L);
        G[Ca][Cb] = G[Cb][Ca] = L;
    }

    Dijkstra();

    printf("%d %d\n", PathNum[C2], Weight[C2]);

    return 0;
}
