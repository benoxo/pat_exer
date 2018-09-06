#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <deque>
#define MAXK 1010
#define MAXN 30
using namespace std;

typedef struct {
    int TotalTime, FrontTime;
    deque<int> Line;
} Window;

int NeedTime[MAXK];
int FinishTime[MAXK];
Window windows[MAXN];

int Minutes(int H, int M) {

}

int main() {
    int N, M, K, Q, H, Minute, OpenTime, CloseTime, i, query;

    cin >> N >> M >> K >> Q;
    for (i = 0; i < K; i++) {
        scanf("%d", NeedTime + i);
    }

    OpenTime = 8*60;
    CloseTime = 17*60;
    for (i = 0; i < N; i++) {
        windows[i].FrontTime = OpenTime;
        windows[i].TotalTime = OpenTime;
    }
    for (i = 0; i < K && i < N*M; i++) {
        int choose = -1;
        int MinLength = 20;
        for (int j = 0; j < N; j++) {
            if (windows[j].Line.size() < MinLength) {
                MinLength = windows[j].Line.size();
                choose = j;
            }
        }
        if (windows[choose].Line.empty()) windows[choose].FrontTime += NeedTime[i];
        windows[choose].Line.push_back(i);
        windows[choose].TotalTime += NeedTime[i];
        FinishTime[i] = windows[choose].TotalTime;
    }

    for (; i < K; i++) {
        int choose = -1;
        int MinTime = 1000000000;
        for (int j = 0; j < N; j++) {
            if (windows[j].FrontTime < MinTime) {
                choose = j;
                MinTime = windows[j].FrontTime;
            }
        }

        windows[choose].Line.pop_front();
        windows[choose].FrontTime += NeedTime[ windows[choose].Line.front() ];
        windows[choose].Line.push_back(i);
        windows[choose].TotalTime += NeedTime[i];
        FinishTime[i] = windows[choose].TotalTime;
    }

    for (int i = 0; i < Q; i++) {
        cin >> query;
        query--;
        if (FinishTime[query]-NeedTime[query] >= CloseTime) cout << "Sorry" << endl;
        else printf("%02d:%02d\n", FinishTime[query]/60, FinishTime[query]%60);
    }

    return 0;
}
