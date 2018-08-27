#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int N, input[100010], S1, S2;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", input + i);
    }
    sort(input, input + N);

    if (N % 2) {
        printf("1 ");
    } else {
        printf("0 ");
    }

    S1 = S2 = 0;
    for (int i = 0; i < N/2; i++) {
        S1 += input[i];
    }
    for (int i = N/2; i < N; i++) {
        S2 += input[i];
    }
    printf("%d", S2-S1);
    return 0;
}
