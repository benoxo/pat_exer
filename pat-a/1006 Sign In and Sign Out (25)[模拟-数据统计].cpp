#include "stdio.h"
#include "string.h"

int main() {
    char first[20], last[20], tmp[20];
    int first_time, last_time, N, h, m, s, millies;
    
    scanf("%d", &N);
    first_time = 24*3600;
    last_time = -1;
    millies = 0;
    while (N--) {
        scanf("%s %d:%d:%d", tmp, &h, &m, &s);
        millies = h*3600 + m*60 + s;
        if (millies < first_time) {
            first_time = millies;
            strcpy(first, tmp);
        }
        
        scanf("%d:%d:%d", &h, &m, &s);
        millies = h*3600 + m*60 + s;
        if (millies > last_time) {
            last_time = millies;
            strcpy(last, tmp);
        }
    }
    
    printf("%s %s", first, last);
    
    return 0;
} 
