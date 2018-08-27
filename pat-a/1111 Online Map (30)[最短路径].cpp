#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 510
#define INF 65535
using namespace std;

struct {
    int Length, Time;
} G[MAXN][MAXN];
int visited[MAXN], path[MAXN], dist[MAXN], times[MAXN],
    MinTime, MinDist, minDistPath[MAXN], minTimePath[MAXN], pres[MAXN];
int N, M, S, D;

int FindMinDist(int V) {
    int MinDist = INF, S = -1;
    for (int W = 0; W < N; W++) {
        if (!visited[W] && dist[W] < MinDist) {
            MinDist = dist[W];
            S = W;
        }
    }
    return S;
}

void Dijkstra(int S, int F) {
    fill(dist, dist + N, INF);
    memset(times, INF, sizeof(times));
    memset(visited, 0, sizeof(visited));
    dist[S] = 0;
    times[S] = 0;
    pres[S] = 0;

    while (true) {
        int V = FindMinDist(S);
        if (V == -1) break;
        visited[V] = true;
        for (int W = 0; W < N; W++) {
            if (visited[W] || G[V][W].Length == INF) continue;
            if (F == 0) {
                if (G[V][W].Length + dist[V] < dist[W]) {
                    dist[W] = G[V][W].Length + dist[V];
                    path[W] = V;
                    times[W] = G[V][W].Time + times[V];
                } else if (G[V][W].Length + dist[V] == dist[W] &&
                           G[V][W].Time + times[V] < times[W]) {
                    path[W] = V;
                    times[W] = G[V][W].Time + times[V];
                }
            } else {
                if (G[V][W].Time + dist[V] < dist[W]) {
                    dist[W] = G[V][W].Time + dist[V];
                    path[W] = V;
                    pres[W] = pres[V] + 1;
                } else if (G[V][W].Time + dist[V] == dist[W]
                           && pres[V] + 1 < pres[W]) {
                    path[W] = V;
                    pres[W] = pres[V] + 1;
                }
            }
        }
    }
}

void InitG() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j].Length = INF;
            G[i][j].Time = INF;
        }
    }
}

void PrintPath(int V, int path[]) {
    if (V != S) {
        PrintPath(path[V], path);
    }
    printf("%d", V);
    if (V != D) printf(" -> ");
    else printf("\n");
}

int main() {
    int V1, V2, one_way, length, t;

    scanf("%d %d", &N, &M);
    InitG();
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d %d", &V1, &V2, &one_way, &length, &t);
        if (!one_way) {
            G[V2][V1].Length = length;
            G[V2][V1].Time = t;
        }
        G[V1][V2].Length = length;
        G[V1][V2].Time = t;
    }

    scanf("%d %d", &S, &D);

    Dijkstra(S, 0);
    memcpy(minDistPath, path, sizeof(path));
    MinDist = dist[D];
    Dijkstra(S, 1);
    memcpy(minTimePath, path, sizeof(path));
    MinTime = dist[D];

    if (memcmp(minDistPath, minTimePath, sizeof(minDistPath)) == 0) {
        printf("Distance = %d; Time = %d: ", MinDist, MinTime);
        PrintPath(D, minDistPath);
    } else {
        printf("Distance = %d: ", MinDist);
        PrintPath(D, minDistPath);
        printf("Time = %d: ", MinTime);
        PrintPath(D, minTimePath);
    }

    return 0;
}
