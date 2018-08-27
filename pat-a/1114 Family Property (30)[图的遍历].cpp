#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 1010
using namespace std;

struct Node {
    int ID, Estate, Area;
    Node() {
        Estate = 0;
        Area = 0;
    }
} Person[MAXN];
vector<int> Map[10010];
int Index[10010];

struct FNode {
    int MinID, Mem;
    double AvgE, AvgA;
} Family[MAXN], F;

int visited[10010];

bool cmp(const struct FNode a, const struct FNode b) {
    if (a.AvgA != b.AvgA) return a.AvgA > b.AvgA;
    return a.MinID < b.MinID;
}

void DFS(int T) {
    visited[T] = true;
    if (T < F.MinID) {
        F.MinID = T;
    }
    F.Mem++;
    if (Index[T] > -1) {
        F.AvgE += Person[ Index[T] ].Estate;
        F.AvgA += Person[ Index[T] ].Area;
    }
    for (int i = 0; i < Map[T].size(); i++) {
        if (!visited[Map[T][i]]) {
            DFS(Map[T][i]);
        }
    }
}

int main() {
    int N, K, ID, Parent, Child, SizeOfFamily;
    scanf("%d", &N);

    memset(Index, -1, sizeof(Index));
    for (int i = 0; i < N; i++) {
        scanf("%d", &ID);
        Person[i].ID = ID;
        Index[ID] = i;
        scanf("%d", &Parent);
        if (Parent > -1) {
            Map[ID].push_back(Parent);
            Map[Parent].push_back(ID);
        }
        scanf("%d", &Parent);
        if (Parent > -1) {
            Map[ID].push_back(Parent);
            Map[Parent].push_back(ID);
        }
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &Child);
            Map[ID].push_back(Child);
            Map[Child].push_back(ID);
        }
        scanf("%d %d", &Person[i].Estate, &Person[i].Area);
    }


    SizeOfFamily = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        ID = Person[i].ID;
        if (!visited[ID]) {
            F.MinID = 10010;
            F.Mem = 0;
            F.AvgE = F.AvgA = 0;
            DFS(ID);
            F.AvgE /= F.Mem;
            F.AvgA /= F.Mem;
            Family[SizeOfFamily] = F;
            SizeOfFamily++;
        }
    }

    sort(Family, Family + SizeOfFamily, cmp);
    printf("%d\n", SizeOfFamily);
    for (int i = 0; i < SizeOfFamily; i++) {
        printf("%04d %d %.3f %.3f\n", Family[i].MinID, Family[i].Mem, Family[i].AvgE, Family[i].AvgA);
    }

    return 0;
}
