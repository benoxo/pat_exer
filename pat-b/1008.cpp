#include "stdio.h"

void reverse(int a[], int n) {
    int tmp;
    for (int i = 0; i < n/2; i++) {
        tmp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tmp;
    }
}

int main() {
    int len, re_n, a[105], i;
    
    scanf("%d %d", &len, &re_n);
    re_n %= len;
    for ( i = 0; i < len; i++) {
        scanf("%d", a + i);
    }
    
    // reverse(a, len - re_n);
    // reverse(a + len - re_n, re_n);
    // reverse(a, len);
    
    for ( i = len - re_n; i < len; i++) {
        printf("%d ", a[i]);
    }
    
    for ( i = 0; i < len - re_n; i++) {
        printf("%d", a[i]);
        if (i != len - re_n - 1) printf(" ");
    }
    
    return 0;
} 
