#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> preorder, inorder, postorder;
int N, V, IsBiTree;

int IndexOfInorder(int begin, int end, int value) {
    for (int i = begin; i <= end; i++) {
        if (value == inorder[i]) return i;
    }
    return -1;
}

int LastIndexOfInorder(int begin, int end, int value) {
    for (int i = end; i >= begin; i--) {
        if (value == inorder[i]) return i;
    }
    return -1;
}

void JudgeTree(int l_pre, int r_pre, int l_in, int r_in, int mirror = 0) {
    if (l_pre > r_pre || !IsBiTree) return;
    int root = preorder[l_pre];
    int rootIndexOfIn = mirror ? LastIndexOfInorder(l_in, r_in, root) : IndexOfInorder(l_in, r_in, root);
    if (rootIndexOfIn == -1) {
        IsBiTree = 0;
        return;
    }
    int leftTreeSize = rootIndexOfIn - l_in;
    JudgeTree(l_pre+1, l_pre+leftTreeSize, l_in, rootIndexOfIn-1);
    JudgeTree(l_pre+leftTreeSize+1, r_pre, rootIndexOfIn + 1, r_in);
    postorder.push_back(root);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &V);
        preorder.push_back(V);
    }
    inorder = preorder;
    sort(inorder.begin(), inorder.end());
    IsBiTree = 1;
    JudgeTree(0, N-1, 0, N-1);

    if (!IsBiTree) {
        sort(inorder.begin(), inorder.end(), std::greater<int>());
        postorder.clear();
        IsBiTree = 1;
        JudgeTree(0, N-1, 0, N-1, 1);
    }

    if (IsBiTree) {
        printf("YES\n");
        for (int i = 0; i < N; i++) {
            printf("%d", postorder[i]);
            if (i < N-1) printf(" ");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
