#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> Tree[110];
int NoChild[110];
int N, M, K, Id, Child, MLevel;

int DFS(int Root, int Level) {
    if (Tree[Root].empty()) {
        NoChild[Level]++;
        if (MLevel < Level) {
            MLevel = Level;
        }
    }
    for (int i = 0; i < Tree[Root].size(); i++) {
        DFS(Tree[Root][i], Level + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &Id, &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &Child);
            Tree[Id].push_back(Child);
        }
    }

    memset(NoChild, 0, sizeof(NoChild));
    MLevel = 0;
    DFS(1, 0);

    for (int i = 0; i < MLevel + 1; i++) {
        printf("%d", NoChild[i]);
        if (i < MLevel) printf(" ");
    }

    return 0;
}
