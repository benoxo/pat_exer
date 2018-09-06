#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct {
    int Data, Next;
}Node;
Node nodes[100100];
vector<int> L, L2;

int main() {
    int First, N, K;
    int Address, Data, Next;

    scanf("%d %d %d", &First, &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Address);
        scanf("%d %d", &nodes[Address].Data, &nodes[Address].Next);
    }

    int Tmp = First;
    while (Tmp != -1) {
        L.push_back(Tmp);
        Tmp = nodes[Tmp].Next;
    }

    for(int i = 0; i < L.size(); i++) {
        if ( nodes[ L[i] ].Data < 0 ) {
            L2.push_back( L[i] );
        }
    }
    for(int i = 0; i < L.size(); i++) {
        if ( nodes[ L[i] ].Data >=0 && nodes[ L[i] ].Data <= K ) {
            L2.push_back( L[i] );
        }
    }
    for (int i = 0; i < L.size(); i++) {
        if ( nodes[ L[i] ].Data > K ) {
            L2.push_back( L[i] );
        }
    }

    printf("%05d %d ", L2.front(), nodes[ L2.front() ].Data);
    for (int i = 1; i < L2.size(); i++) {
        printf("%05d\n%05d %d ", L2[i], L2[i], nodes[ L2[i] ].Data);
    }
    printf("-1\n");
    return 0;
}
