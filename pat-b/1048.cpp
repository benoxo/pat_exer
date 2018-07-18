#include "stdio.h"
#include "string.h"

void reverse(char str[]) {
    int i, len, end;
    char tmp;
    len = strlen(str);
    end = len / 2;
    i = 0;
    while (i < end) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
        i++;
    }
}

int main() {
    char A[110], B[110], S[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    int i, lenB, lenA, index;
    
    scanf("%s %s", A, B);
    lenB = strlen(B);
    lenA = strlen(A);
    reverse(A);
    reverse(B);
    
    while (lenB < lenA) {
        B[lenB++] = '0';
    }
    B[lenB] = '\0';
    while (lenA < lenB) {
        A[lenA++] = '0';
    }
    A[lenA] = '\0';
    i = 0;
    while (i < lenB) {
        if ((i+1) % 2) {
            index = (A[i] + B[i] - '0' - '0') % 13;
            B[i] = S[index];
        } else {
            index = (B[i] + 10 - A[i]) % 10;
            B[i] = S[index];
        }
        i++;
    }
    
    reverse(B);
    
    printf("%s", B);
    
    return 0;
}
