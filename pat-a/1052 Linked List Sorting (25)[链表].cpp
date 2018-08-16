#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct N{
    int Addr, Next, Value;

    bool operator < (const N b) {
        return Value < b.Value;
    }
}Node;

int main() {
    Node nodes[100000];
    vector<Node> L;
    int N, addr, next, value, i, first;

    scanf("%d%d", &N, &first);
    for (i = 0; i < N; i++) {
        scanf("%d %d %d", &addr, &value, &next);
        nodes[addr].Addr = addr;
        nodes[addr].Value = value;
        nodes[addr].Next = next;
    }

    next = first;
    while (next > -1) {
        L.push_back(nodes[next]);
        next = nodes[next].Next;
    }

    sort(L.begin(), L.end());
    printf("%d ", L.size());
    for (i = 0; i < L.size(); i++) {
        printf("%05d\n%05d %d ", L[i].Addr, L[i].Addr, L[i].Value);
    }
    printf("-1\n");

    return 0;
}
