#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

typedef struct Node {
    int V, Pos;
    Node *L, *R;
} *TNode, *Tree;
typedef Tree AvlTree;
int CBT[100];

int Height(AvlTree T) {
    if (T == NULL) return 0;
    return max( Height(T->L), Height(T->R) ) + 1;
}

AvlTree SingleRotateWithLeft(AvlTree T) {
    AvlTree Root = T->L;
    T->L = Root->R;
    Root->R = T;
    return Root;
}

AvlTree SingleRotateWithRight( AvlTree T) {
    AvlTree Root = T->R;
    T->R = Root->L;
    Root->L = T;
    return Root;
}

AvlTree DoubleRotateWithLeft(AvlTree T) {
    AvlTree Root = T->L;
    T->L = SingleRotateWithRight(Root);
    return SingleRotateWithLeft(T);
}

AvlTree DoubleRotateWithRight(AvlTree T) {
    AvlTree Root = T->R;
    T->R = SingleRotateWithLeft(Root);
    return SingleRotateWithRight(T);
}

AvlTree Insert(AvlTree T, int V) {
    if (T == NULL) {
        TNode node = (TNode) malloc( sizeof(struct Node) );
        node->V = V;
        node->L = node->R = NULL;
        return node;
    }

    if (V < T->V) {
        T->L = Insert(T->L, V);
        if ( Height(T->L) - Height(T->R) > 1 ) {
            if ( V < T->L->V ) {
                T = SingleRotateWithLeft(T);
            } else {
                T = DoubleRotateWithLeft(T);
            }
        }
    } else {
        T->R = Insert(T->R, V);
        if ( Height(T->R) - Height(T->L) > 1 ) {
            if ( V > T->R->V ) {
                T = SingleRotateWithRight(T);
            } else {
                T = DoubleRotateWithRight(T);
            }
        }
    }
    return T;
}

void LevelOrderTraversal(AvlTree T) {
    queue<TNode> Q;
    Q.push(T);
    T->Pos = 1;
    while (!Q.empty()) {
        TNode Tmp = Q.front();
        CBT[Tmp->Pos] = true;
        Q.pop();
        if (Tmp->L != NULL) {
            Q.push(Tmp->L);
            Tmp->L->Pos = Tmp->Pos * 2;
        }
        if (Tmp->R != NULL) {
            Q.push(Tmp->R);
            Tmp->R->Pos = Tmp->Pos * 2 + 1;
        }

        printf("%d", Tmp->V);
        if (!Q.empty()) printf(" ");
    }
    printf("\n");
}

int main() {
    int N, K;
    AvlTree T = NULL;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        T = Insert(T, K);
    }

    memset(CBT, false, sizeof(CBT));
    LevelOrderTraversal(T);

    int i;
    for (i = 1; i <= N; i++) {
        if (!CBT[i]) break;
    }
    if (i == N+1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
