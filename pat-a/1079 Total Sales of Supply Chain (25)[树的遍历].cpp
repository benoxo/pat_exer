#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    double P;
    int M;
    vector<int> Childs;
} TNode[100010];

int main() {
    int N, K, D;
    double Price, Rate, Total;
    scanf("%d %lf %lf", &N, &Price, &Rate);

    TNode[0].P = Price;
    Total = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        if (K == 0) {
            scanf("%d", &D);
            TNode[i].M = D;
        }
        for (int j = 0; j < K; j++) {
            scanf("%d", &D);
            TNode[i].Childs.push_back(D);
        }
    }

    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        int size = TNode[i].Childs.size();
        if ( size == 0) {
            Total += TNode[i].M * TNode[i].P;
        } else {
            for (int j = 0; j < size; j++) {
                TNode[ TNode[i].Childs[j] ].P = TNode[i].P * (1 + 0.01*Rate);
                Q.push(TNode[i].Childs[j]);
            }
        }
    }

    printf("%.1lf\n", Total);

    return 0;
}
