#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#define MAXN 1020
#define INF 65535
using namespace std;

typedef struct St {
    int ID, MinDist, MaxDist;
    double AvgDist;
    bool operator < (const St b) {
        if (MinDist != b.MinDist) return MinDist > b.MinDist;
        if (AvgDist != b.AvgDist) return AvgDist < b.AvgDist;
        return ID < b.ID;
    }
} Station;
vector<Station> stations;
int G[MAXN][MAXN], visited[MAXN], dist[MAXN];
int N, M, K, Ds;

int ReadPosition() {
    char str[5];
    scanf("%s", str);
    if (str[0] == 'G') {
        return atoi(str+1) + N;
    } else {
        return atoi(str);
    }
}

int FindMinDist(int V) {
    int MinDist = INF, S = -1;
    for (int W = 1; W <= N+M; W++) {
        if (!visited[W] && dist[W] < MinDist) {
            MinDist = dist[W];
            S = W;
        }
    }
    return S;
}

void Dijkstra(int S) {
    fill(dist, dist+N+M+1, INF);
    memset(visited, false, sizeof(visited));
    dist[S] = 0;

    while (true) {
        int V = FindMinDist(S);
        if (V == -1) break;
        visited[V] = true;
        for (int W = 1; W <= N + M; W++) {
            if (visited[W] || G[V][W] == INF) continue;
            if (G[V][W] + dist[V] < dist[W]) {
                dist[W] = G[V][W] + dist[V];
            }
        }
    }
}

int FindProperStation(int S) {
    int MinDist = INF, MaxDist = -1;
    double AvgDist = 0;
    for (int W = 1; W <= N; W ++) {
        if (dist[W] < MinDist) {
            MinDist = dist[W];
        }
        if (dist[W] > MaxDist) {
            MaxDist = dist[W];
        }
        AvgDist += dist[W];
    }
    AvgDist /= N;
    if (MaxDist <= Ds) {
        Station s;
        s.ID = S - N;
        s.AvgDist = AvgDist;
        s.MaxDist = MaxDist;
        s.MinDist = MinDist;
        stations.push_back(s);
    }
}

int main() {
    int P1, P2, Dist;
    scanf("%d%d%d%d", &N, &M, &K, &Ds);

    fill(G[0], G[0] + MAXN * MAXN, INF);
    for (int i = 0; i < K; i++) {
        P1 = ReadPosition();
        P2 = ReadPosition();
        scanf("%d", &Dist);
        G[P1][P2] = G[P2][P1] = Dist;
    }

    for (int V = N + 1; V <= N + M; V++) {
        Dijkstra(V);
        FindProperStation(V);
    }

    if (stations.empty()) {
        printf("No Solution\n");
    } else {
        sort(stations.begin(), stations.end());
        printf("G%d\n%d.0 %.1lf\n", stations[0].ID, stations[0].MinDist, stations[0].AvgDist);
    }

    return 0;
}
