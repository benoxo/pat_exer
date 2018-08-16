#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

vector<int> Tree[100010];
int N, M, K, lLevel, SizeOfRetailers;
double P, R, lowest;

void DFS(int Root, int level) {
    if (Tree[Root].empty()) {
        if (level < lLevel) {
            lLevel = level;
            lowest = P * pow(1 + R, lLevel);
            SizeOfRetailers = 1;
        } else if (level == lLevel) {
            SizeOfRetailers++;
        }
    }

    for (int i = 0; i < Tree[Root].size(); i++) {
        DFS(Tree[Root][i], level + 1);
    }
}

int main() {
    scanf("%d %lf %lf", &N, &P, &R);
    R /= 100;

    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &M);
            Tree[i].push_back(M);
        }
    }

    lLevel = N + 1;
    DFS(0, 0);
    printf("%.4lf %d", lowest, SizeOfRetailers);

    return 0;
}
