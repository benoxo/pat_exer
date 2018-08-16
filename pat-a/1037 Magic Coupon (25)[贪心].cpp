#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int N, Np, i, j;
    long long C[100010], P[100010], bonus;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%lld", C + i);
    } 
    
    scanf("%d", &Np);
    for (i = 0; i < Np; i++) {
        scanf("%lld", P + i);
    } 
    
    sort(C, C + N);
    sort(P, P + Np);
    
    bonus = 0;
    for (i = 0, j = 0; i < N && C[i] < 0 && j < Np && P[j] < 0; i++, j++) {
        bonus += C[i] * P[j];
    }
    for (i = N-1, j = Np-1; i >=0 && C[i] > 0 && j >= 0 && P[j] > 0; i--, j--) {
        bonus += C[i] * P[j];
    }
    
    printf("%lld", bonus);
    return 0;
}
