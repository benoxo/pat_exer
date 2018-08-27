#include <cstdio>
#include <cstdlib>

typedef struct Node {
    int V;
    struct Node *LChild, *RChild;
} *TNode, *PtrToNode, *Tree;
Tree AvlTree;

int Max(int A, int B) {
    return A > B ? A : B;
}

int GetHeight(TNode node) {
    if (node == NULL) return 0;
    return Max(GetHeight(node->LChild), GetHeight(node->RChild)) + 1;
}

Tree RotateWithLeft(Tree Root) {
    Tree LChild = Root->LChild;
    Root->LChild = LChild->RChild;
    LChild->RChild = Root;
    return LChild;
}

Tree RotateWithRight(Tree Root) {
    Tree RChild = Root->RChild;
    Root->RChild = RChild->LChild;
    RChild->LChild = Root;
    return RChild;
}

Tree DoubleRotateWithLeft(Tree Root) {
    Root->LChild = RotateWithRight(Root->LChild);
    return RotateWithLeft(Root);
}

Tree DoubleRotateWithRight(Tree Root) {
    Root->RChild = RotateWithLeft(Root->RChild);
    return RotateWithRight(Root);
}

Tree Insert(Tree Root, int Value) {
    if (Root == NULL) {
        TNode node = (TNode) malloc(sizeof(struct Node));
        node->V = Value;
        node->LChild = node->RChild = NULL;
        return node;
    }
    if (Value < Root->V) {
        Root->LChild = Insert(Root->LChild, Value);
        if (GetHeight(Root->LChild) - GetHeight(Root->RChild) > 1) {
            if (Value < Root->LChild->V) {
                Root = RotateWithLeft(Root);
            } else {
                Root = DoubleRotateWithLeft(Root);
            }
        }
    } else {
        Root->RChild = Insert(Root->RChild, Value);
        if (GetHeight(Root->RChild) - GetHeight(Root->LChild) > 1) {
            if (Value > Root->RChild->V) {
                Root = RotateWithRight(Root);
            } else {
                Root = DoubleRotateWithRight(Root);
            }
        }
    }
    return Root;
}

int main(){
    int N, K;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        AvlTree = Insert(AvlTree, K);
    }
    printf("%d\n", AvlTree->V);

    return 0;
}
