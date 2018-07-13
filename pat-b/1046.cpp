#include "stdio.h"

int main() {
    int count, a, aguess, b, bguess, adrink, bdrink;
    
    scanf("%d", &count);
    adrink = bdrink = 0;
    
    while (count--) {
        scanf("%d %d %d %d", &a, &aguess, &b, &bguess);
        if ( aguess == bguess ) continue;
        if ( a + b == aguess ) {
            bdrink++;
        } else if ( a + b == bguess ) {
            adrink++;
        }
    }
    printf("%d %d", adrink, bdrink);
    
    return 0;
}
