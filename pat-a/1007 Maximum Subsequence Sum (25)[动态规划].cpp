#include <cstdio>

int main() {
    int K, N[10010], dp[10010], start[10010], Max, Index;

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", N+i);
    }

    dp[0] = N[0];
    Max = N[0];
    Index = 0;
    for (int i = 1; i < K; i++) {
        if (dp[i-1] + N[i] > N[i]) {
            dp[i] = dp[i-1] + N[i];
            start[i] = start[i-1];
        } else {
            dp[i] = N[i];
            start[i] = i;
        }
        if (dp[i] > Max) {
            Max = dp[i];
            Index = i;
        }
    }

    if (Max >= 0) printf("%d %d %d", Max, N[start[Index]], N[Index]);
    else printf("0 %d %d", N[0], N[K-1]);
    return 0;
}
