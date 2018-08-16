#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct Node {
    int V, Lchild, Rchild;
} TNode;

TNode nodes[20];
int counter;

void LevelTraverse(int Root) {
    queue<int> Q;
    Q.push(Root);
    while(!Q.empty()) {
        printf("%d", Q.front());
        if (--counter) printf(" ");
        TNode node = nodes[Q.front()];
        Q.pop();
        if (node.Lchild != -1) Q.push(node.Lchild);
        if (node.Rchild != -1) Q.push(node.Rchild);
    }
};

void InOrderTraverse(int Root) {
    if (Root == -1) return;
    InOrderTraverse(nodes[Root].Lchild);
    printf("%d", Root);
    if (--counter) printf(" ");
    InOrderTraverse(nodes[Root].Rchild);
};

int main() {
    int N, Hash[20], Root;
    char L, R;
    scanf("%d\n", &N);

    memset(Hash, 0, sizeof(Hash));
    for (int i = 0; i < N; i++) {
        scanf("%c %c\n", &R, &L);
        nodes[i].V = i;
        if (L == '-') {
            nodes[i].Lchild = -1;
        } else {
            nodes[i].Lchild = L - '0';
            Hash[L-'0'] = 1;
        }
        if (R == '-') {
            nodes[i].Rchild = -1;
        } else {
            nodes[i].Rchild = R - '0';
            Hash[R-'0'] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (Hash[i] == 0) {
            Root = i;
            break;
        }
    }

    counter = N;
    LevelTraverse(Root);
    printf("\n");
    counter = N;
    InOrderTraverse(Root);

    return 0;
}
