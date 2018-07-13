#include "stdio.h"
#include "string.h"

int main() {
    long long pa, pb;
    char a[20], b[20];
    int da, db, len_a, len_b, i, j;
    
    scanf("%s %d %s %d", a, &da, b, &db);
    len_a = strlen(a);
    len_b = strlen(b);
     
    pa = 0;
    for (i = 0; i < len_a; i++) {
        if ( a[i] == da + '0' ) {
            pa = pa*10 + da; 
        }
    }
    pb = 0;
    for (i = 0; i < len_b; i++) {
        if ( b[i] == db + '0' ) {
            pb = pb*10 + db; 
        }
    }
    
    printf("%lld", pa + pb);
    return 0;
}
