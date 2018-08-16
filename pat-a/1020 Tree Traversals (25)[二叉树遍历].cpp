#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct Node {
    int V;
    Node *lchild, *rchild;
    Node(int value) {
        V = value;
        lchild = NULL;
        rchild = NULL;
    }
}*TNode, *PtrToNode, *BiTree;

vector<int> postorder, inorder;

int IndexInIn(int begin, int end, int value) {
    for (int i = begin; i < end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

BiTree CreateTree(int b_post, int e_post, int b_in, int e_in) {
    if (b_post > e_post) return NULL;
    int root_value = postorder[e_post];
    TNode root = (TNode) malloc(sizeof(struct Node));
    root->V = root_value;
    int sizeOfLeft, rootInIn;
    rootInIn = IndexInIn(b_in, e_in + 1, root_value);
    if (rootInIn != -1) {
        sizeOfLeft = rootInIn - b_in;
        root->lchild = CreateTree(b_post, b_post + sizeOfLeft - 1, b_in, rootInIn - 1);
        root->rchild = CreateTree(b_post + sizeOfLeft, e_post - 1, rootInIn + 1, e_in);
    }
    return root;
}

void LevelTraverse(BiTree tree) {
    queue<TNode> Q;
    Q.push(tree);
    while (!Q.empty()) {
        TNode node = Q.front();
        Q.pop();
        if (node->lchild != NULL) Q.push(node->lchild);
        if (node->rchild != NULL) Q.push(node->rchild);
        printf("%d", node->V);
        if (!Q.empty()) printf(" ");
    }
}

int main() {
    int N, v;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v);
        postorder.push_back(v);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &v);
        inorder.push_back(v);
    }
    BiTree tree = CreateTree(0, N-1, 0, N-1);

    LevelTraverse(tree);

    return 0;
}
