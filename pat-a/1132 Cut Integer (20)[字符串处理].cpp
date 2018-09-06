#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
    int N, K, K1, K2;
    char str[50], S1[50], S2[50];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);

        memset(S1, 0, sizeof(S1));
        memset(S2, 0, sizeof(S2));
        int len = strlen(str);
        memcpy(S1, str, len/2);
        memcpy(S2, str + len/2, len/2);
        K = atoi(str);
        K1 = atoi(S1);
        K2 = atoi(S2);
        if (K1*K2 == 0 || K%(K1*K2)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }

    return 0;
}
