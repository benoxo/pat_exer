#include "stdio.h"
#include "string.h"

int main() {
    char origin[10010], S[7] = "PATest";
    int PATest[6], len, i, j, out;
    
    scanf("%s", origin);
    len = strlen(origin);
    memset(PATest, 0, sizeof(PATest));
    for (i = 0; i < len; i++) {
        for (j = 0; j < 6; j++) {
            if (origin[i] == S[j]) {
                PATest[j]++;
            }
        }
    }
    
    while (true) {
        out = 0;
        for (i = 0; i < 6; i++) {
            if (PATest[i]) {
                printf("%c", S[i]);
                PATest[i]--;
                out = 1; 
            }
        }
        if (!out) break; 
    }
    return 0;
} 
