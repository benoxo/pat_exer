#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 1010
using namespace std;

vector<int> G[MAXN];
int FNum, visited[MAXN], depth[MAXN];
int N, L, M, K;
int user;

void BFS(int V, int Depth) {
    visited[V] = true;
    depth[V] = Depth;
    queue<int> Q;
    Q.push(V);
    while (!Q.empty()) {
        int CV = Q.front();
        Q.pop();
        if (depth[CV] == 0) break;
        for (int i = 0; i < G[CV].size(); i++) {
            int next = G[CV][i];
            if (!visited[next]) {
                Q.push(next);
                depth[next] = depth[CV]-1;
                visited[next] = true;
                FNum++;
            }
        }
    }

}

int main() {
    scanf("%d %d", &N, &L);

    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &user);
            G[user].push_back(i+1);
        }
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &user);
        memset(visited, 0, sizeof(visited));
        FNum = 0;
        BFS(user, L);
        printf("%d\n", FNum);
    }

    return 0;
}
