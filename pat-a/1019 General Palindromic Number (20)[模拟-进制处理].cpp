#include "stdio.h"
#include "string.h"

int main() {
    long long N, base, len, i;
    int res[100];
    
    scanf("%lld%lld", &N, &base);
    len = 0;
    do {
        res[len++] = N % base;
        N = N / base;
    } while (N > 0);
    
    i = 0;
    while (i <= len / 2 && res[i] == res[len-1-i]) i++;
    if (i == len / 2 + 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    while (--len) {
        printf("%d ", res[len]);
    }
    printf("%d", res[0]);
    
    return 0;
}
