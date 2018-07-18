#include "stdio.h"

int main() {
    int N, Z, i, counter, Q[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3,  7, 9, 10, 5, 8, 4, 2};
    char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    char str[20];
    
    scanf("%d", &N);
    counter = 0;
    while (N--) {
        scanf("%s", str);
        Z = 0;
        for (i = 0; i < 17; i++) {
            Z += (str[i] - '0') * Q[i];
        }
        Z = Z % 11;
        if (M[ Z ] != str[17]) {
            counter++;
            printf("%s\n", str);
        }
    }
    if (counter == 0) {
        printf("All passed");
    }
    return 0;
}
