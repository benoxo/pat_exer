#include <cstdio>
#include <cstring>

int main() {
    int N, M, i, HT[1010], d;
    
    scanf("%d %d", &N, &M);
    memset(HT, 0, sizeof(HT));
    for (i = 0; i < N; i++) {
        scanf("%d", &d);
        HT[d]++;
    }
    
    for (i = 1; i <= M / 2; i++) {
        if (HT[i]-- && HT[M-i]--) {
            printf("%d %d", i, M-i);
            break;
        }
    }
    if (i > M / 2) printf("No Solution");
    
    return 0;
}
