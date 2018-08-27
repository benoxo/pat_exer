#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXCOLOR 201
#define MAXSTRIPE 10001

int order[MAXCOLOR];
int given[MAXSTRIPE];
int dp[MAXSTRIPE][MAXCOLOR];
int N, M, L;

int GetMaxLen(int start, int end, int curorder);

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    int color, maxlength;
    for (int i = 1; i <= N; i++) {
        order[i] = -1;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &color);
        order[color] = i;
    }

    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        scanf("%d", given + i);
    }
    memset(dp, -1, sizeof(dp));
    maxlength = GetMaxLen(0, L-1, 0);
    printf("%d", maxlength);
    return 0;
}

int GetMaxLen(int start, int end, int curorder) {
    if (start > end) return 0;
    if (dp[start][curorder] >= 0) return dp[start][curorder];
    if (order[given[start]] < curorder) {
        return dp[start][curorder] = GetMaxLen(start + 1, end, curorder);
    }
    else {
        return dp[start][curorder] = 
            max(GetMaxLen(start + 1, end, order[given[start]]) + 1,
            GetMaxLen(start + 1, end, curorder));
    }
}
