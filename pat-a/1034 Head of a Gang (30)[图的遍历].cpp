#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#define MAXN 2010
using namespace std;

struct Gang {
    string Head;
    int Size, TotalTime, HeadTime;
    bool operator < (const Gang B) {
        return Head < B.Head;
    }
} AGang;

int N, K;
int G[MAXN][MAXN];
vector<string> NameMap;
map<string, int> IDMap;
vector<Gang> Gangs;
int visited[MAXN];
int MaxTime, SizeOfGang;

void BFS(int V) {
    queue<int> Q;
    Q.push(V);
    visited[V] = true;
    int TTime;
    while (!Q.empty()) {
        int T = Q.front();
        Q.pop();
        TTime = 0;
        for (int i = 0; i <MAXN; i++) {
            if (!visited[i] && G[T][i] > 0) {
                Q.push(i);
                AGang.Size++;
                visited[i] = true;
            }
            TTime += G[T][i];
            AGang.TotalTime += G[T][i];
        }
        if (TTime > AGang.HeadTime) {
            AGang.HeadTime = TTime;
            AGang.Head = NameMap[T];
        }
    }
    AGang.TotalTime /= 2;
}

void InitGraph() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            G[i][j] = 0;
        }
    }
}

int main() {
    string NameA, NameB;
    int Weight, IDA, IDB;
    scanf("%d %d", &N, &K);

    InitGraph();
    memset(visited, true, sizeof(visited));

    for (int i = 0; i < N; i++) {
        cin >> NameA >> NameB >> Weight;
        if (IDMap.find(NameA) == IDMap.end()) {
            IDA = NameMap.size();
            NameMap.push_back(NameA);
            IDMap[NameA] = IDA;
        } else {
            IDA = IDMap[NameA];
        }

        if (IDMap.find(NameB) == IDMap.end()) {
            IDB = NameMap.size();
            NameMap.push_back(NameB);
            IDMap[NameB] = IDB;
        } else {
            IDB = IDMap[NameB];
        }

        G[IDA][IDB] += Weight;
        G[IDB][IDA] += Weight;
        visited[IDA] = visited[IDB] = false;
    }

    for (int i = 0; i < MAXN; i++) {
        if (!visited[i]) {
            AGang.TotalTime = 0;
            AGang.Head = "";
            AGang.Size = 1;
            AGang.HeadTime = 0;
            BFS(i);
            if (AGang.TotalTime > K && AGang.Size > 2){
                Gangs.push_back(AGang);
            }
        }
    }

    cout << Gangs.size() << endl;
    sort(Gangs.begin(), Gangs.end());
    for (int i = 0; i < Gangs.size(); i++) {
        cout << Gangs[i].Head << " " << Gangs[i].Size << endl;
    }

    return 0;
}
