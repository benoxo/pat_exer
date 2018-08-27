#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 100010
using namespace std;

int main() {
    int N, M, Hash[MAXN], Present[MAXN];
    int PA, PB;
    vector<int> singles;

    memset(Hash, -1, sizeof(Hash));
    memset(Present, false, sizeof(Present));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &PA, &PB);
        Hash[PA] = PB;
        Hash[PB] = PA;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &PA);
        Present[PA] = true;
    }

    for (int i = 0; i < MAXN; i++) {
        if ((Present[i] && Hash[i] < 0) ||
            (Present[i] && Hash[i] > -1 && !Present[ Hash[i] ])) {
            singles.push_back(i);
        }
    }

    printf("%d\n", singles.size());
    for (int i = 0; i < singles.size(); i++) {
        printf("%05d", singles[i]);
        if (i < singles.size()-1) printf(" ");
    }
    return 0;
}
