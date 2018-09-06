#include <cstdio>
#include <cstring>

typedef struct Node {
    char V[20];
    int L, R;
} *TNode, *Tree;

struct Node nodes[30];
int Root;

void InorderTraversal(int T) {
    if (T != Root && (nodes[T].L != -1 || nodes[T].R != -1))
        printf("(");
    if (nodes[T].L != -1) InorderTraversal(nodes[T].L);
    printf("%s", nodes[T].V);
    if (nodes[T].R != -1) InorderTraversal(nodes[T].R);
    if (T != Root && (nodes[T].L != -1 || nodes[T].R != -1))
        printf(")");
}

int main() {
    int N, Hash[30];

    scanf("%d\n", &N);
    memset(Hash, 0, sizeof(Hash));
    for (int i = 1; i <= N; i++) {
        scanf("%s %d %d\n", nodes[i].V, &nodes[i].L, &nodes[i].R);
        if (nodes[i].L != -1) Hash[nodes[i].L] = 1;
        if (nodes[i].R != -1) Hash[nodes[i].R] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (Hash[i] == 0) {
            Root = i;
            break;
        }
    }

    InorderTraversal(Root);
    return 0;
}
