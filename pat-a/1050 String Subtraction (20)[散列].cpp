#include <cstdio>
#include <cstring>

int main() {
    char S1[10010], S2[10010];
    int i, H[266], len1, len2;
    
    fgets(S1, sizeof(S1), stdin);
    fgets(S2, sizeof(S2), stdin);
    len1 = strlen(S1);
    len2 = strlen(S2);
    
    memset(H, 0, sizeof(H));
    for (i = 0; i < len2; i++) {
        H[ S2[i] ] = 1;
    }
    
    for (i = 0; i < len1; i++) {
        if (H[ S1[i] ] == 0) {
            printf("%c", S1[i]);
        }
    }
    
    return 0;
}
