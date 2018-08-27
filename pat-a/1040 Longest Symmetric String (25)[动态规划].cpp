#include <cstdio>
#include <cstring>

int dp[1010][1010];

int main() {
    int slen, ans;
    char S[1010];

    fgets(S, sizeof(S), stdin);
    slen = strlen(S);
    memset(dp, 0, sizeof(dp));
    ans = 1;
    for (int i = 0; i < slen; i++) {
        dp[i][i] = 1;
        if (i < slen-1 && S[i] == S[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }

    for (int L = 3; L <= slen; L++) {
        for (int i = 0; i < slen-L; i++) {
            int right = i+L-1;
            if (S[i] == S[right] && dp[i+1][right-1] == 1) {
                dp[i][right] = 1;
                ans = L;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
