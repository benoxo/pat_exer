#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> G[10010], DeepestRoot;
int N, visited[10010], Deepest, CurDeepest;

void DFS(int V) {
    visited[V] = 1;
    for (int i = 0; i < G[V].size(); i++) {
        if (!visited[ G[V][i] ]) {
            DFS(G[V][i]);
        }
    }
}

int CountComponents() {
    int Count = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i);
            Count++;
        }
    }
    return Count;
}

void GetDepth(int V, int Depth) {
    visited[V] = 1;
    bool HasChild = false;
    for (int i = 0; i < G[V].size(); i++) {
        if (!visited[ G[V][i] ] ) {
            HasChild = true;
            GetDepth(G[V][i], Depth + 1);
        }
    }
    if (!HasChild) {
        if (Depth > CurDeepest) {
            CurDeepest = Depth;
        }
    }
}

int GetDeepest() {
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        CurDeepest = 0;
        GetDepth(i, 1);
        if (Deepest < CurDeepest) {
            Deepest = CurDeepest;
            DeepestRoot.clear();
            DeepestRoot.push_back(i);
        } else if (Deepest == CurDeepest) {
            DeepestRoot.push_back(i);
        }
    }
}

int main() {
    int V1, V2, Connect;

    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &V1, &V2);
        G[V1].push_back(V2);
        G[V2].push_back(V1);
    }

    memset(visited, 0, sizeof(visited));
    Connect = CountComponents();
    if (Connect > 1) {
        printf("Error: %d components", Connect);
    } else {
        Deepest = 0;
        GetDeepest();
        for (int i = 0; i < DeepestRoot.size(); i++) {
            printf("%d\n", DeepestRoot[i]);
        }
    }

    return 0;
}
