#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 100;
int preorder[MAXN];
int postorder[MAXN];
vector<int> inorder;

int FindInPost(int V, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (postorder[i] == V) {
            return i;
        }
    }
    return -1;
}

bool UniqueTree(int l_pre, int r_pre, int l_post, int r_post) {
    if (l_pre > r_pre) return false;
    if (l_pre == r_pre) {
        inorder.push_back(preorder[l_pre]);
        return true;
    }
    bool res = true;
    int Root = preorder[l_pre];
    int LRoot = preorder[l_pre + 1];
    int LRootInPost = FindInPost(LRoot, l_post, r_post);
    int LSize = LRootInPost - l_post + 1;
    res = UniqueTree(l_pre + 1, l_pre + LSize, l_post, LRootInPost);
    inorder.push_back(Root);
    res = res & UniqueTree(l_pre + LSize + 1, r_pre, LRootInPost + 1, r_post - 1);
    return res;
}

int main() {
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", preorder + i);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", postorder + i);
    }

    if (UniqueTree(0, N-1, 0, N-1) ) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = 0; i < N; i++) {
        printf("%d", inorder[i]);
        if (i < N-1) printf(" ");
    }
    printf("\n");

    return 0;
}
