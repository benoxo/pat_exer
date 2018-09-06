#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef int SetType;
const int MAXN = 10010;
SetType Set[MAXN];

int Root(int V) {
    if (Set[V] > 0) {
        return Set[V] = Root(Set[V]);
    } else {
        return V;
    }
}

void Combine(int Root1, int Root2) {
    if (Set[Root1] <= Set[Root2]) {
        Set[Root1] += Set[Root2];
        Set[Root2] = Root1;
    } else {
        Set[Root2] += Set[Root1];
        Set[Root1] = Root2;
    }
}

int main() {
    int N, K, Q, V1, V2, MIndex, Size;

    scanf("%d", &N);
    MIndex = 1;
    memset(Set, -1, sizeof(Set));
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        scanf("%d", &V1);
        if (V1 > MIndex) MIndex = V1;
        for (int j = 1; j < K; j++) {
            scanf("%d", &V2);
            if (V2 > MIndex) MIndex = V2;
            Combine(Root(V1), Root(V2));
        }
    }

    Size = 0;
    for (int i = 1; i <= MIndex; i++) {
        if (Set[i] < 0) Size++;
    }
    printf("%d %d\n", Size, MIndex);

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &V1, &V2);
        if (Root(V1) == Root(V2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
