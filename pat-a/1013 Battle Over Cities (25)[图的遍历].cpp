#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> G[1010];
int N, M, K, Deleted;
int visited[1010];

void DFS(int V) {
    visited[V] = true;
    for (int i = 0; i < G[V].size(); i++) {
        if (G[V][i] == Deleted || visited[ G[V][i] ]) continue;
        DFS(G[V][i]);
    }
}

int CountCounnected() {
    int Size = 0;
    for (int i = 1; i <= N; i++) {
        if (i == Deleted || visited[i]) continue;
        DFS(i);
        Size++;
    }
    return Size;
}

int main() {
    int V1, V2, ConnectedSize;

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &V1, &V2);
        G[V1].push_back(V2);
        G[V2].push_back(V1);
    }

    for (int i = 0; i < K; i++) {
        scanf("%d", &Deleted);
        memset(visited, 0, sizeof(visited));
        ConnectedSize = CountCounnected();
        printf("%d\n", ConnectedSize - 1);
    }

    return 0;
}
