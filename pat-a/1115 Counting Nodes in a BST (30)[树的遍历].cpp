#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int V;
    Node *L, *R;
} *TNode, *Tree;

int N1, N2;

Tree Insert(Tree T, int V) {
    if (T == NULL) {
        TNode node = (TNode)malloc( sizeof(struct Node) );
        node->V = V;
        node->L = node->R = NULL;
        return node;
    }
    if (V <= T->V) {
        T->L = Insert(T->L, V);
    } else {
        T->R = Insert(T->R, V);
    }
    return T;
}

void BFS(Tree T) {
    queue<TNode> Q;
    Q.push(T);
    TNode last = T;
    int Size = 0;
    N2 = N1 = 0;
    while (!Q.empty()) {
        TNode tmp = Q.front();
        Q.pop();
        Size++;
        if (tmp->L != NULL) Q.push(tmp->L);
        if (tmp->R != NULL) Q.push(tmp->R);
        if (tmp == last) {
            N2 = N1;
            N1 = Size;
            last = Q.back();
            Size = 0;
        }
    }
}

int main() {
    int N, K;
    Tree BST = NULL;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        BST = Insert(BST, K);
    }

    BFS(BST);
    printf("%d + %d = %d", N1, N2, N1 + N2);
    return 0;
}
