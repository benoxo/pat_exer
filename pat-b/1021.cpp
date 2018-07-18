#include "stdio.h"
#include "string.h"

int main() {
    int S[10], i, len;
    char N[1010];
    
    scanf("%s", &N);
    memset(S, 0, sizeof(S));
    len = strlen(N);
    for (i = 0; i < len; i++) {
        S[ N[i] - '0' ]++;
    }
    
    for (i = 0; i < 10; i++) {
        if (S[i] == 0) continue;
        printf("%d:%d\n", i, S[i]);
    }
    return 0;
}
