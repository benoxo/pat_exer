#include <cstdio>

int main() {
    int M, N, i, j, domain, time, color;

    scanf("%d %d", &M, &N);

    domain = -1;
    time = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &color);
            if (time == 0) {
                domain = color;
                time = 1;
            } else if (color != domain) {
                time--;
            } else {
                time++;
            }
        }
    }
    printf("%d", domain);
    return 0;
}
