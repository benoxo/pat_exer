#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
    int N, K, input[1010], flag;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        flag = true;
        for (int j = 0; j < K; j++) {
            scanf("%d", input + j);
        }

        for (int j = 0; j < K && flag; j++) {
            for (int k = 0; k < j && flag; k++) {
                if (input[j] == input[k] ||
                    abs(input[j]-input[k]) == abs(j-k)){
                    flag = false;
                }
            }
        }

        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
