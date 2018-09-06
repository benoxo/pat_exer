#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int V;
    Node *L, *R;
    Node(int _v):V(_v), L(NULL), R(NULL) {}
} *TNode, *Tree;

int N, K, black;
int inorder[100], preorder[100];
Tree T;

bool cmp(int A, int B) {
    return abs(A) < abs(B);
}

int FindRootIn(int Root, int start, int end) {
    for (int i = end; i >= start ; i--) {
        if (inorder[i] == Root) {
            return i;
        }
    }
    return -1;
}

/*Tree CreateTree(int l_pre, int r_pre, int l_in, int r_in) {
    if (l_pre > r_pre) return NULL;
    TNode node = new Node(preorder[l_pre]);
    node->V = preorder[l_pre];
    int rindex = FindRootIn(node->V, l_in, r_in);
    int lsize = rindex - l_in;
    node->L = CreateTree(l_pre + 1, l_pre + lsize, l_in, rindex - 1);
    node->R = CreateTree(l_pre + lsize + 1, r_pre, rindex + 1, r_in);
    return node;
}*/

Tree CreateTree(Tree T, int X) {
    if (T == NULL) {
        return new Node(X);
    }
    if (abs(X) < abs(T->V)) {
        T->L = CreateTree(T->L, X);
    } else {
        T->R = CreateTree(T->R, X);
    }
    return T;
}

bool IsRBTree(Tree T, int blackSize) {
    if (T == NULL) {
        if (black == -1) {
            black = blackSize;
        } else if ( blackSize != black ) {
            return false;
        }
        return true;
    }
    if (T->V < 0) {
        if (T->L != NULL && T->L->V < 0) return false;
        if (T->R != NULL && T->R->V < 0) return false;
        return IsRBTree(T->L, blackSize) && IsRBTree(T->R, blackSize);
    } else {
        return IsRBTree(T->L, blackSize+1) && IsRBTree(T->R, blackSize+1);
    }
}

int main() {

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        T = NULL;
        for (int j = 0; j < N; j++) {
            scanf("%d", preorder + j);
            T = CreateTree(T, preorder[j]);
        }

        //memcpy(inorder, preorder, sizeof(preorder));
        //sort(inorder, inorder + N, cmp);
        //T = CreateTree(0, N-1, 0, N-1);
        black = -1;
        if ( T->V > 0 && IsRBTree(T, 0) ) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
