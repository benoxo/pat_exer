#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 510;
vector<int> G[MAXN];
bool visited[MAXN] = {false};

void DFS(int V) {
    visited[V] = true;
    for (int W = 0; W < G[V].size(); W++) {
        if (!visited[G[V][W]]) DFS(G[V][W]);
    }
}

int main() {
    int Nv, Ne, V1, V2, odd;
    bool connect = true;
    cin >> Nv >> Ne;

    for (int i = 0; i < Ne; i++) {
        cin >> V1 >> V2;
        G[V1].push_back(V2);
        G[V2].push_back(V1);
    }
    DFS(1);
    for (int W = 1; W <= Nv; W++) {
        if (!visited[W]) connect = false;
    }

    odd = 0;
    for (int i = 1; i <= Nv; i++) {
        cout << G[i].size();
        if (i < Nv) cout << " ";
        if (G[i].size()%2) {
            odd++;
        }
    }
    cout << endl;

    if (connect && odd == 0) {
        cout <<"Eulerian" << endl;
    } else if (connect && odd == 2) {
        cout <<"Semi-Eulerian" << endl;
    } else {
        cout << "Non-Eulerian" << endl;
    }

    return 0;
}
