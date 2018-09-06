#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, i;
    double tlen, ropes[10010] = {0};

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%lf", ropes+i);
    }

    sort(ropes, ropes + N);
    tlen = ropes[0];
    for (i = 1; i < N; i++) {
        tlen = floor(tlen/2 + ropes[i]/2);
    }
    printf("%d\n", (int)tlen);
    return 0;
}
