#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 10010
using namespace std;

typedef struct {
    int V1, V2;
} Edge;
vector<Edge> edges;

int main() {
    int N, M, K, V1, V2, Nv, total, query, visited[MAXN];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &V1, &V2);
        Edge e;
        e.V1 = V1;
        e.V2 = V2;
        edges.push_back(e);
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &Nv);
        memset(visited, 0, sizeof(visited));
        total = 0;
        for (int j = 0; j < Nv; j++) {
            scanf("%d", &query);
            visited[query] = true;
        }

        int flag = true;
        for (int j = 0; j < edges.size(); j++) {
            if (!visited[ edges[j].V1 ] && !visited[ edges[j].V2 ] ) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }


    return 0;
}
