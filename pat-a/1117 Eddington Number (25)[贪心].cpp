#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int rides[MAXN];

int main() {
    int N, i, E;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", rides + i);
    }
    sort(rides, rides + N);

    E = 1;
    for (i = N-1; i >= 0; i--) {
        if (rides[i] > E) {
            E++;
        }
    }

    printf("%d\n", E-1);

    return 0;
}
