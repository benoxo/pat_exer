#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct {
    int Addr, Next, Value;
} Node;

int main() {
    Node nodes[100000];
    int N, addr, next, value, i, first;
    vector<Node> L, R;
    int ape[10010];

    scanf("%d %d", &first, &N);
    for (i = 0; i < N; i++) {
        scanf("%d %d %d", &addr, &value, &next);
        nodes[addr].Addr = addr;
        nodes[addr].Value = value;
        nodes[addr].Next = next;
    }

    memset(ape, 0, sizeof(ape));
    next = first;
    while (next > -1) {
        value = abs(nodes[next].Value);
        if (ape[value] > 0) {
            R.push_back(nodes[next]);
        } else {
            ape[value] = 1;
            L.push_back(nodes[next]);
        }
        next = nodes[next].Next;
    }

    printf("%05d %d ", L.front().Addr, L.front().Value);
    for (i = 1; i < L.size(); i++) {
        printf("%05d\n%05d %d ", L[i].Addr, L[i].Addr, L[i].Value);
    }
    printf("-1\n");

    if (R.size() > 0) printf("%05d %d ", R.front().Addr, R.front().Value);
    for (i = 1; i < R.size(); i++) {
        printf("%05d\n%05d %d ", R[i].Addr, R[i].Addr, R[i].Value);
    }
    if (R.size() > 0) printf("-1\n");
    return 0;
}
