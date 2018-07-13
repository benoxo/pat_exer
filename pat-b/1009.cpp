#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 85 

int main() {
    char str[MAXLEN][MAXLEN];
    int count;
    
    count = 0;
    while (scanf("%s", str[count]) != EOF) {
        count++;
    }
    while (count--) {
        printf("%s", str[count]);
        if (count) printf(" ");
    }
    
    return 0;
}
