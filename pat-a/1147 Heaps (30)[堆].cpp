#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#define MAXN 10010
using namespace std;

int lorder[MAXN];
int N, M;
vector<int> postorder;

bool IsHeap(int T, int HeapType) {
    if (2*T > N) return true;
    if (HeapType) {
        int MaxChild = lorder[T*2];
        if (T*2 + 1 < N && lorder[T*2+1] > MaxChild)
            MaxChild = lorder[T*2 + 1];
        if (lorder[T] < MaxChild) return false;
        else return IsHeap(2*T, HeapType) && IsHeap(2*T+1, HeapType);
    } else {
        int MinChild = lorder[T*2];
        if (T*2 + 1 < N && lorder[T*2+1] < MinChild)
            MinChild = lorder[T*2 + 1];
        if (lorder[T] > MinChild) return false;
        else return IsHeap(2*T, HeapType) && IsHeap(2*T+1, HeapType);
    }
}

void PostOrderTraversal(int T) {
    if (T > N) return;
    PostOrderTraversal(T*2);
    PostOrderTraversal(T*2+1);
    postorder.push_back(lorder[T]);
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", lorder + j);
        }

        if (IsHeap(1, 1)) {
            printf("Max Heap\n");
        } else if (IsHeap(1, 0)) {
            printf("Min Heap\n");
        } else {
            printf("Not Heap\n");
        }
        postorder.clear();
        PostOrderTraversal(1);

        for (int i = 0; i < postorder.size(); i++) {
            printf("%d", postorder[i]);
            if (i < postorder.size()-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
