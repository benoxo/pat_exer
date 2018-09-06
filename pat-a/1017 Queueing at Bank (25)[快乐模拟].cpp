#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int ComeTime, NeedTime;
} Customer;

vector<Customer> costomers;
int windows[110];

bool cmp(Customer A, Customer B) {
    return A.ComeTime < B.ComeTime;
}

int Seconds(int H, int M, int S) {
    return H * 3600 + M * 60 + S;
}

int main() {
    int N, K, H, M, S, Need, TotalWait, OpenTime, CloseTime;
    cin >> N >> K;

    OpenTime = Seconds(8, 0, 0);
    CloseTime = Seconds(17, 0, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d:%d:%d %d", &H, &M, &S, &Need);
        Customer c;
        c.ComeTime = Seconds(H, M, S);
        c.NeedTime = Need * 60;
        if (c.ComeTime <= CloseTime) costomers.push_back(c);
    }
    sort(costomers.begin(), costomers.end(), cmp);

    TotalWait = 0;
    fill(windows, windows + K, OpenTime);
    int i;
    for (i = 0; i < costomers.size(); i++) {
        int spare_win = -1;
        int MinTime = 1000000000;
        for (int j = 0; j < K; j++) {
            if (windows[j] < MinTime) {
                MinTime = windows[j];
                spare_win = j;
            }
        }

        if (costomers[i].ComeTime < MinTime) {
            TotalWait += MinTime - costomers[i].ComeTime;
            windows[spare_win] += costomers[i].NeedTime;
        } else {
            windows[spare_win] = costomers[i].ComeTime + costomers[i].NeedTime;
        }
    }

    printf("%.1f", TotalWait*1.0/60/i);

    return 0;
}
