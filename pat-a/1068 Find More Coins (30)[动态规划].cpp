#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <functional>
using namespace std;

int N, M, coins[10010], dp[10010][110], choose[10010][110];

int main() {
    stack<int> S;

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", coins + i);
    }

    sort(coins + 1, coins + N + 1, greater<int>());
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j >= coins[i] && dp[i-1][j-coins[i]] + coins[i] >= dp[i-1][j]) {
                dp[i][j] = dp[i-1][j-coins[i]] + coins[i];
                choose[i][j] = true;
            } else {
                dp[i][j] = dp[i-1][j];
                choose[i][j] = false;
            }
        }
    }

    if (dp[N][M] < M) {
        printf("No Solution\n");
    } else {
        int remain = M;
        int row = N;
        while (remain) {
            if (choose[row][remain]) {
                printf("%d", coins[row]);
                remain -= coins[row];
                if (remain) printf(" ");
            }
            row--;
        }
    }

    return 0;
}
