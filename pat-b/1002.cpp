#include "stdio.h"
#include "string.h"

int main() {
    int sum, len, i;
    char S[1010];
    char H[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    scanf("%s", S);
    len = strlen(S);
    sum = 0;
    for (i = 0; i < len; i++) {
        sum += S[i] - '0';
    }
    
    sprintf(S, "%d", sum);
    len = strlen(S);
    for (i = 0; i < len-1; i++) {
        printf("%s ", H[S[i] - '0']);
    }
    printf("%s", H[S[len-1] - '0']);
    
    return 0; 
}
