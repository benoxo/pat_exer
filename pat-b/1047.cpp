#include "stdio.h"
#include "string.h"

int main() {
    int TS[1010], N, i, TNo, SNo, score, MS, MNo;
    
    scanf("%d", &N);
    memset(TS, 0, sizeof(TS));
    MS = 0;
    for (i = 0; i < N; i++) {
        scanf("%d-%d %d", &TNo, &SNo, &score);
        TS[TNo] += score;
        if (TS[TNo] > MS) {
            MS = TS[TNo];
            MNo = TNo; 
        }
    }
    
    printf("%d %d", MNo, MS);
    return 0;
}
