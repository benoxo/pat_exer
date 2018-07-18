#include "stdio.h"
#include "string.h"

int main() {
    int n1, n2, n3, N, n1s, n2s, n3s, i;
    char str[100];
    
    scanf("%s", str);
    N = strlen(str);
    n1 = n3 = (N+2)/3-1;
    n2 = N - n1*2;
    n1s = 0;
    n2s = n1;
    n3s = N-1;
    
    while(n1s < n2s) {
        printf("%c", str[n1s++]);
        for (i = 0; i < n2-2; i++) {
            printf(" ");
        }
        printf("%c", str[n3s--]);
        printf("\n");
    }
    while (n2s <= n3s) {
        printf("%c", str[n2s++]);
    }
    return 0;
}
