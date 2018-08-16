#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

vector<int> fac, tmp, ans;
int N, K, P, maxFacSum;

void initFac() {
    int Ns;
    for (int i = 0; (Ns = (int)round(pow(i, P))) <= N; i++) {
        fac.push_back(Ns);
    }
}

void DFS(int index, int nowK, int sum, int facSum) {
    if (nowK == 0 && sum == 0) {
        if (facSum > maxFacSum) {
            maxFacSum = facSum;
            ans = tmp;
        }
        return;
    }
    if (nowK < 0 || sum < 0) return;
    if (index > 0) {
        tmp.push_back(index);
        DFS(index, nowK-1, sum-fac[index], facSum+index);
        tmp.pop_back();
        DFS(index-1, nowK, sum, facSum);
    }
}

int main() {
    scanf("%d %d %d", &N, &K, &P);
    initFac();
    maxFacSum = -1;
    DFS(fac.size() - 1, K, N, 0);

    if (maxFacSum == -1) {
        printf("Impossible\n");
    } else {
        printf("%d = ", N);
        for (int i = 0; i < ans.size(); i++) {
            printf("%d^%d", ans[i], P);
            if (i < ans.size() - 1) printf(" + ");
        }
    }
    return 0;
}

