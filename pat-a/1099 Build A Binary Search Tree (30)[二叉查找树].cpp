#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node {
    int V, Lchild, Rchild;
} TNode;

TNode Tree[110];
int values[110];
int N, index;

void PreOrderTraversal(int root) {
    if (root == -1) return;
    PreOrderTraversal(Tree[root].Lchild);
    Tree[root].V = values[index++];
    PreOrderTraversal(Tree[root].Rchild);
}

void LevelOrderRaversal(int root) {
    queue<TNode> Q;
    Q.push(Tree[root]);
    while (!Q.empty()) {
        TNode node = Q.front();
        Q.pop();
        if (node.Lchild != -1) Q.push(Tree[node.Lchild]);
        if (node.Rchild != -1) Q.push(Tree[node.Rchild]);
        printf("%d", node.V);
        if (!Q.empty()) printf(" ");
    }
}

int main() {
    int l, r;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &l, &r);
        Tree[i].Lchild = l;
        Tree[i].Rchild = r;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", values + i);
    }

    index = 0;
    sort(values, values + N);
    PreOrderTraversal(0);

    LevelOrderRaversal(0);
    return 0;
}
