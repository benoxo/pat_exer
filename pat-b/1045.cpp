#include <cstdio>
#include <cstring>
#include <vector>
#define INF 0x7fffffff
using namespace std;

int main() {
    int MaxInLeft[100010], MinInRight[100010], i, A[100010], N, min, max, counter;
    vector<int> candidate;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", A + i);
    }

    max = 0;
    for (i = 0; i < N; i++) {
        if (max < A[i]) {
            max = A[i];
        }
        MaxInLeft[i] = max;
    }
    min = INF;
    for (i = N-1; i >= 0; i--) {
        if (min > A[i]) {
            min = A[i];
        }
        MinInRight[i] = min;
    }

    counter = 0;
    for (i = 0; i < N; i++) {
        if (A[i] <= MinInRight[i] && A[i] >= MaxInLeft[i]) {
            counter++;
            candidate.push_back(A[i]);
        }
    }
    printf("%d\n", counter);
    vector<int>::iterator it = candidate.begin();
    while (it != candidate.end()) {
        if (it != candidate.begin()) printf(" ");
        printf("%d", *it);
        it++;
    }
    printf("\n");
    return 0;
}
