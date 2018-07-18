#include "stdio.h"
#include "string.h"

int main() {
    long long a, b, sum;
    int len, i;
    char s[20];
    
    scanf("%lld%lld", &a, &b);
    sum = a + b;
    if (sum < 0) {
        sum = -sum;
        printf("-");
    }
    sprintf(s, "%lld", sum);
    len = strlen(s);
    i = 0;
    while (i < len) {
        printf("%c", s[i++]);
        if (i < len && (len-i) % 3 == 0) {
            printf(",");
        }
    }
    
    return 0;
} 
