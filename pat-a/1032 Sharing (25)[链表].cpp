#include <cstdio>
#include <vector>
using namespace std;

typedef struct {
    int Addr, Next;
    char Value;
}Node;

int main() {
    Node nodes[100000];
    vector<Node> L1, L2;
    int N, addr, next, cur1, cur2, i, j, first1, first2, diff, flag;
    char value;

    scanf("%d%d%d", &first1, &first2, &N);
    for (i = 0; i < N; i++) {
        scanf("%d %c %d", &addr, &value, &next);
        nodes[addr].Addr = addr;
        nodes[addr].Value = value;
        nodes[addr].Next = next;
    }

    next = first1;
    while (next > -1) {
        L1.push_back(nodes[next]);
        next = nodes[next].Next;
    }

    next = first2;
    while (next > -1) {
        L2.push_back(nodes[next]);
        next = nodes[next].Next;
    }

    diff = L1.size() - L2.size();
    cur1 = cur2 = 0;
    if (diff > 0) cur1 += diff;
    else cur2 -= diff;
    flag = 0;
    while (cur1 < L1.size() && cur2 < L2.size()) {
        if (L1[cur1].Addr == L2[cur2].Addr) {
            flag = 1; break;
        }
        cur1++; cur2++;
    }
    if (flag) {
        printf("%05d\n", L1[cur1].Addr);
    } else {
        printf("-1\n");
    }

    return 0;
}
