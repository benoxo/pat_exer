#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int M, N, K, nPush, P;
    vector<int> S;
    vector<int> Seq;
    vector<int>::iterator cPop;
    scanf("%d %d %d", &M, &N, &K);

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> P;
            Seq.push_back(P);
        }
        nPush = 1; cPop = Seq.begin();
        while (cPop != Seq.end() && nPush <= N) {
            S.push_back(nPush++);
            while (cPop != Seq.end() && S.back() == *cPop) {
                S.pop_back();
                cPop++;
            }
            if (S.size() >= M) break;
        }

        if (cPop != Seq.end()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        Seq.clear();
        S.clear();
    }

    return 0;
}

