#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAXN 510
#define INF 65535
using namespace std;

int Cmax, N, Sp, M;
int G[MAXN][MAXN], capacity[MAXN], collected[MAXN], dist[MAXN], need[MAXN], MinNeed, MinBack;
vector<int> path[MAXN], CPath, MinPath;

int FindMinDist(int S) {
    int MinDist = INF, MinV = -1;
    for (int i = 0; i <= N; i++) {
        if (!collected[i] && dist[i] < MinDist) {
            MinDist = dist[i];
            MinV = i;
        }
    }
    return MinV;
}

void Dijkstra(int S) {
    fill(dist, dist + MAXN, INF);
    dist[S] = 0;
    need[S] = 0;

    while (true) {
        int V = FindMinDist(S);
        if (V == -1) break;
        collected[V] = true;

        for (int W = 1; W <= N; W++) {
            if (collected[W] || G[V][W] == INF) continue;
            if (dist[V] + G[V][W] < dist[W]) {
                dist[W] = dist[V] + G[V][W];
                path[W].clear();
                path[W].push_back(V);
            } else if (dist[V] + G[V][W] == dist[W]) {
                path[W].push_back(V);
            }
        }
    }
}

void CalNeedBack(int &need, int &remain) {
    need = remain = 0;
    for (int i = CPath.size()-2; i >= 0; i--) {
        int Tmp = CPath[i];
        if (remain + capacity[Tmp] > Cmax/2) {
            remain = remain + capacity[Tmp] - Cmax/2;
        } else {
            need += Cmax/2 - capacity[Tmp] - remain;
            remain = 0;
        }
    }
}

void DFS(int V) {
    if (V == 0) {
        int need, remain;
        CalNeedBack(need, remain);
        if (need < MinNeed) {
            MinNeed = need;
            MinBack = remain;
            MinPath = CPath;
        } else if ( need == MinNeed && remain < MinBack ) {
            MinBack = remain;
            MinPath = CPath;
        }
    }

    for (int i = 0; i < path[V].size(); i++) {
        CPath.push_back( path[V][i] );
        DFS(path[V][i]);
        CPath.pop_back();
    }
}

int main() {
    int Si, Sj, T;
    scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);

    fill(G[0], G[0] + MAXN*MAXN, INF);
    for (int i = 0; i < N; i++) {
        scanf("%d", capacity + i + 1);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &Si, &Sj, &T);
        G[Si][Sj] = G[Sj][Si] = T;
    }

    memset(collected, false, sizeof(collected));
    Dijkstra(0);
    MinNeed = MinBack = INF;
    CPath.push_back(Sp);
    DFS(Sp);

    printf("%d ", MinNeed);
    for (int i = MinPath.size()-1; i > 0; i--) {
        printf("%d->", MinPath[i]);
    }
    printf("%d %d\n", Sp, MinBack);

    return 0;
}
