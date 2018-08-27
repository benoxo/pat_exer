#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N, G[110][110], m, n, K;
    vector<int> init;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        init.push_back(K);
    }

    n = (int)sqrt(N);
    while (N % n) n--;
    m = N / n;

    int row = 0;
    int colum = 0;
    int now = 0;
    int lastrow, lastcolum;

    sort(init.begin(), init.end(), greater<int>());
    while (now < init.size()) {
        row++;
        colum++;
        lastrow = m-row+1;
        lastcolum = n-colum+1;

        for (int i = colum; i <= lastcolum && now < init.size(); i++) {
            G[row][i] = init[now++];
        }
        for (int j = row+1; j < lastrow && now < init.size(); j++) {
            G[j][lastcolum] = init[now++];
        }
        for (int i = lastcolum; i >= colum && now < init.size(); i--) {
            G[lastrow][i] = init[now++];
        }
        for (int j = lastrow-1; j > row && now < init.size(); j--) {
            G[j][row] = init[now++];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", G[i][j]);
            if (j < n) printf(" ");
        }
        printf("\n");
    }


    return 0;
}
