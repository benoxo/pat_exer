#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> Tree[110], TmpPath;
vector<int> Path[110];
int Weight[110];

int N, M, S, K, ID, Child, SizeOfPath;

void DFS(int Root, int Sum) {
    if (Tree[Root].empty()) {
        if (Sum == S) {
            Path[SizeOfPath++] = TmpPath;
        }
        return;
    }

    for (int i = 0; i < Tree[Root].size(); i++) {
        int child = Tree[Root][i];
        TmpPath.push_back( child );
        DFS(child, Sum + Weight[child]);
        TmpPath.pop_back();
    }
}

bool CmpByWeight(int A, int B) {
    return Weight[A] > Weight[B];
}

int main() {
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", Weight + i);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &ID, &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &Child);
            Tree[ID].push_back(Child);
        }
        sort(Tree[ID].begin(), Tree[ID].end(), CmpByWeight);
    }

    TmpPath.push_back(0);
    SizeOfPath = 0;
    DFS(0, Weight[0]);

    for (int i = 0; i < SizeOfPath; i++) {
        for (int j = 0; j < Path[i].size(); j++) {
            printf("%d", Weight[ Path[i][j] ]);
            if (j < Path[i].size() - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
