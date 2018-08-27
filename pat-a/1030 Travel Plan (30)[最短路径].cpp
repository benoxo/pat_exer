#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 510
#define INF 65535
using namespace std;

struct {
    int Dist, Cost;
} G[MAXN][MAXN];

int visited[MAXN], path[MAXN], cost[MAXN], dist[MAXN];
int N, M, S, D;

int FindMinDist(int V) {
    int MinDist = INF, S = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] < MinDist) {
            MinDist = dist[i];
            S = i;
        }
    }
    return S;
}

void Dijkstra(int S) {
    memset(visited, false, sizeof(visited));
    fill(dist, dist + N, INF);
    dist[S] = 0;
    cost[S] = 0;

    while (true) {
        int V = FindMinDist(S);
        if (V == -1) break;
        visited[V] = true;
        for (int W = 0; W < N; W++) {
            if (visited[W] || G[V][W].Dist == INF) continue;
            if (G[V][W].Dist + dist[V] < dist[W]) {
                dist[W] = G[V][W].Dist + dist[V];
                path[W] = V;
                cost[W] = cost[V] + G[V][W].Cost;
            } else if (G[V][W].Dist + dist[V] == dist[W]) {
                if (G[V][W].Cost + cost[V] < cost[W]) {
                    path[W] = V;
                    cost[W] = cost[V] + G[V][W].Cost;
                }
            }
        }
    }
}

void InitG() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j].Cost = INF;
            G[i][j].Dist = INF;
        }
    }
}

void PrintPath(int S, int D) {
    if (D != S) {
        PrintPath(S, path[D]);
    }
    printf("%d ", D);
}

int main() {
    int V1, V2, Dist, Cost;
    scanf("%d%d%d%d", &N, &M, &S, &D);

    InitG();
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &V1, &V2, &Dist, &Cost);
        G[V1][V2].Cost = G[V2][V1].Cost = Cost;
        G[V1][V2].Dist = G[V2][V1].Dist = Dist;
    }

    Dijkstra(S);

    PrintPath(S, D);
    printf("%d %d\n", dist[D], cost[D]);
    return 0;
}
