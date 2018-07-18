#include "stdio.h"
const int GK = 29*17;
const int SK = 29;

int main() {
    long long g, s, k, sum;
    
    sum = 0;
    scanf("%lld.%lld.%lld", &g, &s, &k);
    sum += g*GK + s*SK + k;
    scanf("%lld.%lld.%lld", &g, &s, &k);
    sum += g*GK + s*SK + k;
    
    printf("%lld.%lld.%lld", sum/GK, sum%GK/SK, sum%SK);
    
    return 0;
}
