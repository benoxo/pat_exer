#include "stdio.h"
#include "string.h"

int main() {
    char str[110][280], c;
    int N, len[110], i, j;
    
    scanf("%d\n", &N);
    for (i = 0; i < N; i++) {
        gets(str[i]);
        len[i] = strlen(str[i]);
    }
    
    i = 0;
    while (i < len[0]) {
        c = str[0][len[0] - 1 - i];
        j = 1;
        while (j < N && i < len[j] && str[j][ len[j] - i - 1 ] == c) {
            j++;
        }
        if (j < N) {
            break;
        }
        i++;
    }
    
    if (i == 0) {
        printf("nai");
    } else {
        printf("%s", str[0] + len[0] - i);
    }
    
    return 0;
} 
