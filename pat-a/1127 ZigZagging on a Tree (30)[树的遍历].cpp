#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

typedef struct Node {
    int V;
    Node *L, *R;
    Node(int _v): V(_v), L(NULL), R(NULL) {}
} *TNode, *Tree;

const int MAXN = 50;
int inorder[MAXN], postorder[MAXN];
vector<int> zigorder;
Tree T;

int IndexInIn(int V, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (inorder[i] == V) {
            return i;
        }
    }
    return -1;
}

Tree CreateTree(int l_post, int r_post, int l_in, int r_in) {
    if (l_post > r_post) return NULL;
    int Root = postorder[r_post];
    TNode T = (TNode)new Node(Root);
    int RIndex = IndexInIn(Root, l_in, r_in);
    int LSize = RIndex - l_in;
    T->L = CreateTree(l_post, l_post + LSize - 1, l_in, RIndex - 1);
    T->R = CreateTree(l_post + LSize, r_post - 1, RIndex + 1, r_in);
    return T;
}

void ZigZag(Tree T) {
    deque<TNode> Q;
    Q.push_back(T);
    TNode last = T;
    zigorder.push_back(T->V);
    int level = 0;

    while (!Q.empty()) {
        TNode Tmp = Q.front();
        Q.pop_front();
        if (Tmp->L != NULL) Q.push_back(Tmp->L);
        if (Tmp->R != NULL) Q.push_back(Tmp->R);
        if (last == Tmp) {
            if (level%2) {
                for (int i = Q.size()-1; i >= 0; i--) {
                    zigorder.push_back(Q[i]->V);
                }
            } else {
                for (int i = 0; i < Q.size(); i++) {
                    zigorder.push_back(Q[i]->V);
                }
            }
            last = Q.back();
            level++;
        }
    }
}

int main() {
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", inorder + i);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", postorder + i);
    }

    T = NULL;
    T = CreateTree(0, N-1, 0, N-1);
    ZigZag(T);

    for (int i = 0; i < N; i++) {
        printf("%d", zigorder[i]);
        if (i < N-1) printf(" ");
    }
    return 0;
}
