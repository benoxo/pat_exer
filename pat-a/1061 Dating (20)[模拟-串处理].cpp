#include "stdio.h"
#include "string.h"

int main() {
    char S[5][100], days[][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i, len[5], hour;
    
    for (i = 0; i < 4; i++) {
        scanf("%s", S+i);
        len[i] = strlen(S[i]);
    }
    
    for (i = 0; i < len[0] && i < len[1]; i++) {
        if (S[0][i] >= 'A' && S[0][i] <= 'G' && S[0][i] == S[1][i]) break;
    }
    printf("%s ", days[S[0][i]-'A']);
    
    for (i = i + 1; i < len[0] && i < len[1]; i++) {
        if (S[0][i] <= 'N' && S[0][i] == S[1][i]) break;
    }
    if (S[0][i] > '9') {
        hour = S[0][i] - 'A' + 10;
    } else {
        hour = S[0][i] - '0';
    }
    printf("%02d:", hour);
    
    for (i = 0; i < len[2] && i < len[3]; i++) {
        if (S[2][i] > '9' && S[2][i] == S[3][i]) break;
    }
    printf("%02d", i);
    
    return 0;
} 
