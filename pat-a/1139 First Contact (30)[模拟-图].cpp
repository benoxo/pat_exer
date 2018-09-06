#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define INF 65535
using namespace std;

const int MAXN = 10000;

typedef struct E {
    int V1, V2;
    bool operator <(struct E b) const {
        if (V1 != b.V1) return V1 < b.V1;
        return V2 < b.V2;
    }
    E(int _v1, int _v2) : V1(_v1), V2(_v2){};
} Edge;

int N, M, K;
vector<int> G[MAXN];
int Gender[MAXN];
vector<Edge> Path;

void Solve(int A, int B) {
    for (int i = 0; i < G[A].size(); i++) {
        int C = G[A][i];
        if (Gender[C] != Gender[A]) continue;
        for (int j = 0; j < G[B].size(); j++) {
            int D = G[B][j];
            if (Gender[D] != Gender[B]) continue;
            if (A == D || B == C) continue;

            for (int k = 0; k < G[C].size(); k++) {
                if (G[C][k] == D) {
                    Edge e(C, D);
                    Path.push_back(e);
                }
            }
        }
    }
}

int main() {
    int V1, V2;
    char S1[10], S2[10];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%s %s", S1, S2);
        if (S1[0] == '-') {
            V1 = atoi(S1+1);
            Gender[V1] = 0;
        } else {
            V1 = atoi(S1);
            Gender[V1] = 1;
        }

        if (S2[0] == '-') {
            V2 = atoi(S2+1);
            Gender[V2] = 0;
        } else {
            V2 = atoi(S2);
            Gender[V2] = 1;
        }
        G[V1].push_back(V2);
        G[V2].push_back(V1);
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &V1, &V2);
        Path.clear();
        Solve(abs(V1), abs(V2));
        sort(Path.begin(), Path.end());
        printf("%d\n", Path.size());
        for (int i = 0; i < Path.size(); i++) {
            printf("%04d %04d\n", Path[i].V1, Path[i].V2);
        }
    }

    return 0;
}
