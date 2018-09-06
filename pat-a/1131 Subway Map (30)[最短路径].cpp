#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#define INF 65535
#define MAXN 10010
using namespace std;

typedef struct {
    int Dest, Line;
} Edge;

vector<Edge> G[MAXN];
bool visited[MAXN];
vector<Edge> path, MinPath;
deque<int> line, MinLine;
int N, M, S1, S2, K, S, D;
vector<int> stations;

void DFS(int V) {
    if (!MinPath.empty() && path.size() > MinPath.size()) return;
    if (V == D) {
        if (MinPath.empty() || path.size() < MinPath.size()) {
            MinPath = path;
            MinLine = line;
        } else if (path.size() == MinPath.size()
                   && line.size() < MinLine.size()) {
            MinPath = path;
            MinLine = line;
        }
        return;
    }
    visited[V] = true;
    for (int W = 0; W < G[V].size(); W++) {
        Edge e = G[V][W];
        if (visited[ G[V][W].Dest ]) continue;
        path.push_back(G[V][W]);
        bool newLine = false;
        if (line.empty() || line.back() != G[V][W].Line) {
            line.push_back(G[V][W].Line);
            newLine = true;
        }
        DFS(G[V][W].Dest);
        if (newLine) line.pop_back();
        path.pop_back();
    }
    visited[V] = false;
}


int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &M);
        S1 = -1;
        for (int j = 0; j < M; j++) {
            scanf("%d", &S2);
            if (S1 != -1) {
                Edge e1;
                e1.Dest = S2;
                e1.Line = i;
                G[S1].push_back(e1);
                Edge e2;
                e2.Dest = S1;
                e2.Line = i;
                G[S2].push_back(e2);
            }
            S1 = S2;
        }
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &S, &D);
        memset(visited, false, sizeof(visited));
        path.clear();
        MinPath.clear();
        line.clear();
        MinLine.clear();
        DFS(S);

        printf("%d\n", MinPath.size());
        int start, end;
        start = S;
        int size = MinLine.size();
        int j = 0;
        while (j < MinPath.size()) {
            while (j < MinPath.size() && MinLine.front() == MinPath[j].Line) j++;
            end = j-1;
            printf("Take Line#%d from %04d to %04d.\n", MinLine.front(), start, MinPath[end].Dest);
            start = MinPath[end].Dest;
            MinLine.pop_front();
        }

    }

    return 0;
}
