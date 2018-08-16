#include <cstdio>
#include <algorithm>
using namespace std;

int A[110], B[110], N;

int JudgeLoop() {
    int step = 2, i;
    while (step < N) {
        for (i = step/2; i < N; i += step) {
            if (B[i] < B[i-1]) {
                break;
            }
        }
        if (i < N) break;
        step *= 2;
    }

    return step;
};


int main() {
    int i, step;
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", A + i);
    }
    for (i = 0; i < N; i++) {
        scanf("%d", B + i);
    }

    for (i = 0; i < N-1; i++) {
        if (B[i] > B[i + 1]) break;
    }
    step = i;
    for (i += 1; i < N; i++) {
        if (A[i] != B[i]) break;
    }

    if (i == N) {
        printf("Insertion Sort\n");
        sort(B, B + step + 2);
    } else {
        printf("Merge Sort\n");
        step = JudgeLoop();
        for (i = 0; i + step < N; i += step) {
            sort(B + i, B + i + step);
        }
        if (i < N) {
            sort(B + i, B + N);
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d", B[i]);
        if (i != N-1) printf(" ");
    }
    return 0;
}
