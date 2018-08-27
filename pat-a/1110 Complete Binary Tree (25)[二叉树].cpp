#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
    int left, right, pos;
} Nodes[50];

int Tree[50];

int ReadChild() {
    char str[5];
    scanf("%s", str);
    if (str[0] != '-') return atoi(str);
    else return -1;
}

int main() {
    int N, Hash[50], Root;

    scanf("%d\n", &N);
    memset(Hash, 0, sizeof(Hash));
    memset(Tree, -1, sizeof(Tree));
    for (int i = 0; i < N; i++) {
        Nodes[i].left = ReadChild();
        Nodes[i].right = ReadChild();
        Hash[Nodes[i].left] = 1;
        Hash[Nodes[i].right] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (Hash[i] == 0) {
            Root = i;
            break;
        }
    }

    queue<int> Q;
    Q.push(Root);
    Tree[1] = Root;
    Nodes[Root].pos = 1;
    while (!Q.empty()) {
        int T = Q.front();
        int pos = Nodes[T].pos;
        Q.pop();
        if (Nodes[T].left >= 0) {
            int lchild = Nodes[T].left;
            Q.push(lchild);
            Tree[pos*2] = lchild;
            Nodes[lchild].pos = pos * 2;
        }
        if (Nodes[T].right >= 0) {\
            int rchild = Nodes[T].right;
            Q.push(rchild);
            Tree[pos*2+1] = rchild;
            Nodes[rchild].pos = pos*2+1;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (Tree[i] == -1) {
            printf("NO %d", Root);
            return 0;
        }
    }
    printf("YES %d", Tree[N]);

    return 0;
}
