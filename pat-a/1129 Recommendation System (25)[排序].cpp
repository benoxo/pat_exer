#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int items[50000];
vector<int> re;

bool cmp(int A, int B) {
    if (items[A] != items[B]) return items[A] > items[B];
    else return A < B;
}

int main() {
    int N, K, I, inserted, size;

    memset(items, 0, sizeof(items));
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &I);
        items[I]++;

        if (re.size() > 0) {
            printf("%d: ", I);
            for (int i = 0; i < re.size() && i < K; i++) {
                printf("%d", re[i]);
                if (i < re.size()-1 && i < K - 1) printf(" ");
            }
            printf("\n");
        }

        int j;
        for (j = 0; j < re.size(); j++) {
            if (re[j] == I) break;
        }
        if (j == re.size()) {
            if (re.size() < K + 1) {
                re.push_back(I);
            } else {
                re[ K ] = I;
            }
        }
        sort(re.begin(), re.end(), cmp);
    }

    return 0;
}
