#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> origin;
int Tree[1010];
int N, V, Root, index;

void CreateTree(int root) {
    if (root > N) return;
    CreateTree(root*2);
    Tree[root] = origin[index++];
    CreateTree(root*2 + 1);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &V);
        origin.push_back(V);
    }
    sort(origin.begin(), origin.end());

    index = 0;
    CreateTree(1);

    for (int i = 1; i <= N; i++) {
        printf("%d", Tree[i]);
        if (i < N) printf(" ");
    }

    return 0;
}
