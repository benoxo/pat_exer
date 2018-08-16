#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int N, HT[110], ins[110], i, d;
    
    scanf("%d", &N);
    memset(HT, 0, sizeof(HT));
    for (i = 0; i < N; i++) {
        scanf("%d", &d);
        ins[i] = d;
        while (d != 1) {
            if (d <= 100) HT[d]++;
            if (d % 2) {
                d = (3 * d + 1) / 2;
            } else {
                d /= 2;
            }
        }
    }
    
    sort(ins, ins + N);
    i = N;
    while (HT[ins[i-1]] != 1) i--;
    printf("%d", ins[i-1]);
    for (i = i - 1; i > 0; i--) {
        if (HT[ins[i-1]] == 1) {
            printf(" %d", ins[i-1]);
        }
    }
    
    return 0;
}
