#include <cstdio>
#include <algorithm>
#include <cstring>

int main() {
    int N, M, L, order[210], color, stripe[10010], dp[10010], cmax[10010], O, Size;

    scanf("%d", &N);
    scanf("%d", &M);
    memset(order, -1, sizeof(order));
    for (int i = 0; i < M; i++) {
        scanf("%d", &O);
        order[O] = i;
    }
    scanf("%d", &L);
    Size = 0;
    for (int i = 0; i < L; i++) {
        scanf("%d", &color);
        if (order[color] >= 0) {
            stripe[Size++] = order[color];
        }
    }

    int ans = -1;
    for (int i = 0; i < Size; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (dp[j] + 1 > dp[i] && stripe[j] <= stripe[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = std::max(ans, dp[i]);

    }
    printf("%d", ans);
    return 0;
}
