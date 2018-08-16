#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

int main() {
    set<int> sets[55];
    int N, M, K, i, j, C, s1, s2, total, common;

    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &M);
        for (j = 0; j < M; j++) {
            scanf("%d", &C);
            sets[i].insert(C);
        }
    }

    scanf("%d", &K);
    for (i = 0; i < K; i++) {
        scanf("%d%d", &s1, &s2);
        common = 0;
        set<int>::iterator it = sets[s1].begin();
        while (it != sets[s1].end()) {
            if (sets[s2].find(*it) != sets[s2].end()) {
                common++;
            }
            it++;
        }

        printf("%.1lf%%\n", (double)(common)
               / (sets[s1].size() + sets[s2].size() - common) * 100);
    }

    return 0;
}
