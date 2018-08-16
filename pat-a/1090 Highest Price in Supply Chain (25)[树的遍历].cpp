#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
    double P;
    vector<int> Childs;
} TNode[100100];

double highest, R, P;
int N, i, parent, Root, Mexp;

void DFS(int Node) {
    for (int i = 0; i < TNode[Node].Childs.size(); i++) {
        int child = TNode[Node].Childs[i];
        TNode[ child ].P = TNode[Node].P * (1+R);
        if (TNode[child].P > highest) {
            highest = TNode[child].P;
            Mexp = 1;
        } else if (TNode[child].P == highest) {
            Mexp++;
        }
        DFS(child);
    }
}

int main() {
    scanf("%d %lf %lf", &N, &P, &R);
    R = R / 100;
    for (int i = 0; i < N; i++) {
        scanf("%d", &parent);
        if (parent >= 0) {
            TNode[parent].Childs.push_back(i);
        } else {
            Root = i;
        }
    }

    TNode[Root].P = P;
    highest = P;
    Mexp = 1;
    DFS(Root);

    printf("%.2lf %d\n", highest, Mexp);
    return 0;
}
