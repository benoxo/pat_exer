#include <cstdio>
#include <cstring>

int main() {
    char A[100], B[100];
    int broken[200], i, j, lenA, lenB, C;
    
    scanf("%s", A);
    scanf("%s", B);
    lenA = strlen(A);
    lenB = strlen(B);
    
    i = j = 0;
    memset(broken, 0, sizeof(broken));
    while (i < lenA) {
        if (A[i] <= 'z' && A[i] >= 'a') {
            C = A[i] + 'A' - 'a';
        } else {
            C = A[i];
        }
        
        if (B[j] != A[i] && broken[C] == 0) {
            printf("%c", C);
            broken[C]++;
        }
        if (B[j] == A[i]) j++;
        i++;
    }
    
    return 0; 
} 
