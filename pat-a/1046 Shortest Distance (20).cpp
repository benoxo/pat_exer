#include "stdio.h"

int main() {
    int N, M, dist[100010], distfrom1[100010], from, end, mindist;
    
    scanf("%d", &N);
    distfrom1[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", dist + i);
        distfrom1[i] = distfrom1[i-1] + dist[i];
    }
    
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &from, &end);
        mindist = distfrom1[end-1] - distfrom1[from-1];
        if (mindist < 0) mindist = -mindist;
        if (mindist > distfrom1[N] - mindist) {
            mindist = distfrom1[N] - mindist;
        }
        printf("%d\n", mindist);
    }
    
    return 0;
}
