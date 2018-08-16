#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> Tree[110];
int NumInLevel[110];
int MLevel, MNode;

void DFS(int Root, int level) {
    NumInLevel[level]++;
    if (NumInLevel[level] > MNode) {
        MLevel = level;
        MNode = NumInLevel[level];
    }
    for (int i = 0; i < Tree[Root].size(); i++) {
        DFS(Tree[Root][i], level + 1);
    }
}

int main() {
    int N, M, Idx, Child, K, i;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &Idx, &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &Child);
            Tree[Idx].push_back(Child);
        }
    }

    memset(NumInLevel, 0, sizeof(NumInLevel));
    MLevel = 1; MNode = 1;
    DFS(1, 1);

    printf("%d %d", MNode, MLevel);

    return 0;
}
