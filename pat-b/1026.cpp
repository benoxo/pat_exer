#include "stdio.h"
#define CLK_TCK 100
 
int main() {
    int c1, c2, mins;
    
    scanf("%d %d", &c1, &c2);
    mins = ( c2 - c1 + CLK_TCK / 2 ) / CLK_TCK;
    printf("%02d:%02d:%02d", mins / 3600, mins / 60 % 60, mins % 60);
    
    return 0;
}
