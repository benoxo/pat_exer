#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#define MAXN 220
#define INF 65535
using namespace std;

vector<string> NameMap;
map<string, int> IDMap;

int G[MAXN][MAXN], visited[MAXN], path[MAXN], cost[MAXN], pre[MAXN], happiness[MAXN], routes[MAXN];
int H[MAXN];
int N, K, S, D;

int ReadCity() {
    string name;
    int Id;
    cin >> name;
    if (IDMap.find(name) == IDMap.end()) {
        Id = NameMap.size();
        NameMap.push_back(name);
        IDMap[name] = Id;
    } else {
        Id = IDMap[name];
    }
    return Id;
}

int FindMinDist(int V) {
    int MinDist = INF, S = -1;
    for (int W = 0; W < N; W++) {
        if (!visited[W] && cost[W] < MinDist) {
            MinDist = cost[W];
            S = W;
        }
    }
    return S;
}

void Dijkstra(int S) {
    fill(cost, cost + N, INF);
    memset(visited, false, sizeof(visited));
    cost[S] = 0;
    happiness[S] = 0;
    pre[S] = 0;
    routes[S] = 1;

    while (true) {
        int V = FindMinDist(S);
        if (V == -1) break;
        visited[V] = true;
        for (int W = 0; W < N; W++) {
            if (visited[W] || G[V][W] == INF) continue;
            if (G[V][W] + cost[V] < cost[W]) {
                cost[W] = G[V][W] + cost[V];
                happiness[W] = H[W] + happiness[V];
                pre[W] = pre[V] + 1;
                routes[W] = routes[V];
                path[W] = V;
            } else if (G[V][W] + cost[V] == cost[W]) {
                if (happiness[W] < H[W] + happiness[V]) {
                    happiness[W] = H[W] + happiness[V];
                    pre[W] = pre[V] + 1;
                    path[W] = V;
                } else if (happiness[W] == H[W] + happiness[V]) {
                    if (pre[V] + 1 < pre[W]) {
                        pre[W] = pre[V] + 1;
                        path[W] = V;
                    }
                }
                routes[W] += routes[V];
            }
        }
    }

}

void PrintfRoute(int S, int V) {
    if (S != V) {
        PrintfRoute(S, path[V]);
    }
    cout << NameMap[V];
    if (V != IDMap["ROM"]) cout << "->";
}

int main() {
    int Id1, Id2, D;
    scanf("%d %d", &N, &K);
    S = ReadCity();
    for (int i = 0; i < N-1; i++) {
        Id1 = ReadCity();
        scanf("%d", H + Id1);
    }

    fill(G[0], G[0] + MAXN*MAXN, INF);
    for (int i = 0; i < K; i++) {
        Id1 = ReadCity();
        Id2 = ReadCity();
        scanf("%d", &D);
        G[Id1][Id2] = G[Id2][Id1] = D;
    }

    D = IDMap["ROM"];
    Dijkstra(S);

    printf("%d %d %d %d\n", routes[D], cost[D], happiness[D], happiness[D]/pre[D]);
    PrintfRoute(S, D);
    return 0;
}
