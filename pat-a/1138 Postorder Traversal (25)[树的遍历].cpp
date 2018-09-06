#include <cstdio>
#include <cstring>

int preorder[50010], inorder[50010];
int found = false;

int FindInIn(int S, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (inorder[i] == S) {
            return i;
        }
    }
    return -1;
}

void GetPostorder(int l_pre, int r_pre, int l_in, int r_in) {
    if (l_pre > r_pre) return;
    if (l_pre == r_pre && !found) {
        found = true;
        printf("%d\n", preorder[l_pre]);
    }
    int Root = preorder[l_pre];
    int RIndex = FindInIn(Root, l_in, r_in);
    int LSize = RIndex - l_in;
    if (!found) GetPostorder(l_pre + 1, l_pre + LSize, l_in, RIndex - 1);
    if (!found) GetPostorder(l_pre + LSize + 1, r_pre, RIndex + 1, r_in);
}

int main() {
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", preorder + i);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", inorder + i);
    }

    GetPostorder(0, N-1, 0, N-1);

    return 0;
}
