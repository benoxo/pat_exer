#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef struct {
    int Addr, Value, Next;
} Node, *PtrToNode;

int main() {
    Node nodes[100010];
    int N, K, First, Addr, Value, NextAddr, Next;
    vector<Node> Q;

    scanf("%d%d%d", &First, &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &Addr, &Value, &NextAddr);
        nodes[Addr].Addr = Addr;
        nodes[Addr].Value = Value;
        nodes[Addr].Next = NextAddr;
    }

    Next = First;
    while (Next != -1) {
        Q.push_back(nodes[Next]);
        Next = nodes[Next].Next;
    }

    for (int i = 0; i + K <= Q.size(); i+=K) {
        for (int j = 0; j < K/2; j++) {
            Node tmp = Q[i+j];
            Q[i+j] = Q[i+K-j-1];
            Q[i+K-j-1] = tmp;
        }
    }

    for (int i = 0; i < Q.size()-1; i++) {
        Q[i].Next = Q[i+1].Addr;
    }
    Q.back().Next = -1;

    for (int i = 0; i < Q.size()-1; i++) {
        printf("%05d %d %05d\n", Q[i].Addr, Q[i].Value, Q[i].Next);
    }
    printf("%05d %d %d\n", Q.back().Addr, Q.back().Value, Q.back().Next);

    return 0;
}
