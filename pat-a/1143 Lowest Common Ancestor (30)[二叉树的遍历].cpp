#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#define MAXN 10010
using namespace std;

typedef struct Node {
    int V;
    Node *L, *R;
    Node(int _v): V(_v), L(NULL), R(NULL){}
} *TNode, *Tree, *BSTree;

BSTree T;
set<int> Exist;
int preorder[MAXN], inorder[MAXN];

/*Tree Insert(Tree T, int V) {
    if (T == NULL) {
        TNode node = new Node(V);
        return node;
    }
    if (T->V > V) {
        T->L = Insert(T->L, V);
    } else {
        T->R = Insert(T->R, V);
    }
    return T;
}*/

int FindinIn(int V, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == V) return i;
    }
    return -1;
}

Tree CreateTree(int l_pre, int r_pre, int l_in, int r_in) {
    if (l_pre > r_pre) return NULL;
    TNode node = new Node(preorder[l_pre]);
    int Root = preorder[l_pre];
    int RIndex = FindinIn(Root, l_in, r_in);
    int LSize = RIndex - l_in;
    node->L = CreateTree(l_pre + 1, l_pre + LSize, l_in, RIndex-1);
    node->R = CreateTree(l_pre + LSize + 1, r_pre, RIndex + 1, r_in);
    return node;
}

bool FindNode(Tree T, int V) {
    if (T == NULL) return false;
    if (T->V == V) {
        return true;
    } else if (V < T->V) {
        return FindNode(T->L, V);
    } else {
        return FindNode(T->R, V);
    }
}

void FindLCA(Tree T, int U, int V) {
    if (T == NULL) return;
    int Min = min(U, V);
    int Max = max(U, V);

    if (Max == T->V) {
        printf("%d is an ancestor of %d.\n", T->V, Min);
    } else if (Min == T->V) {
        printf("%d is an ancestor of %d.\n", T->V, Max);
    } else if (Max < T->V) {
        FindLCA(T->L, U, V);
    } else if (Min > T->V) {
        FindLCA(T->R, U, V);
    } else {
        printf("LCA of %d and %d is %d.\n", U, V, T->V);
    }
}

int main() {
    int N, M, V, U;

    scanf("%d %d", &M, &N);
    T = NULL;
    for (int i = 0; i < N; i++) {
        scanf("%d", &V);
        inorder[i] = preorder[i] = V;
        Exist.insert(V);
    }
    sort(inorder, inorder + N);
    T = CreateTree(0, N-1, 0, N-1);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &U, &V);
        bool LChild = Exist.find(U) != Exist.end();
        bool RChild = Exist.find(V) != Exist.end();
        if ( !LChild && !RChild) {
            printf("ERROR: %d and %d are not found.\n", U, V);
        } else if ( !LChild ) {
            printf("ERROR: %d is not found.\n", U);
        } else if ( !RChild ) {
            printf("ERROR: %d is not found.\n", V);
        } else {
            FindLCA(T, U, V);
        }
    }

    return 0;
}
