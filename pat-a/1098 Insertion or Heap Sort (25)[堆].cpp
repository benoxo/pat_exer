#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int initial[110];
int sorted[110];
int N;

int IsInsertion() {
    int K;
    for (int i = 0; i < N-1; i++) {
        if (sorted[i] > sorted[i+1]) {
            K = i;
            break;
        }
    }
    for (int i = K+1; i < N; i++) {
        if (sorted[i] != initial[i]) return -1;
    }
    return K+1;
}

int HeapRound() {
    int K;
    for (int i = N-1; i > 0; i--) {
        if (sorted[i] < sorted[i-1]) {
            K = i;
            break;
        }
    }
    return K + 1;
}

int main() {
    int K;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", initial + i);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", sorted + i);
    }

    K = IsInsertion();
    if (K > -1) {
        printf("Insertion Sort\n");
        sort(sorted, sorted + K + 1);
    } else {
        K = HeapRound();
        printf("Heap Sort\n");
        pop_heap(sorted, sorted + K);
    }

    for (int i = 0; i < N; i++) {
        printf("%d", sorted[i]);
        if (i < N-1) printf(" ");
    }

    return 0;
}
