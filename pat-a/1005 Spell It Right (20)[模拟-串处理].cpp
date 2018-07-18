#include "stdio.h"
#include "string.h"

int main() {
    char N[110], S[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum, len, i;
    
    scanf("%s", N);
    sum = 0;
    i = 0;
    len = strlen(N);
    while (i < len) {
        sum += N[i++] - '0';
    }
    
    sprintf(N, "%d", sum);
    len = strlen(N);
    i = 0;
    while (i < len) {
        if (i > 0) printf(" ");
        printf("%s", S[ N[i] - '0' ]);
        i++;
    }
    
    return 0;
}
