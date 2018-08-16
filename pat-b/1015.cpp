#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Pe {
    long long ID;
    int V_Grade, T_Grade, G;
    
    bool operator < (const Pe &b) {
        if (G != b.G) return G > b.G;
        if (V_Grade + T_Grade != b.V_Grade + b.T_Grade) {
            return V_Grade + T_Grade > b.V_Grade + b.T_Grade;
        } else if (V_Grade != b.V_Grade) {
            return V_Grade > b.V_Grade;
        } else {
            return ID < b.ID;
        }
    }
} Person, *PtrToPerson; 

Person P[100000];
int N, M, i, vg, tg, L, H;
long long id;

int main() {
    scanf("%d %d %d", &N, &L, &H);
    M = 0;
    for (i = 0; i < N; i++) {
        scanf("%lld %d %d", &id, &vg, &tg);
        if (vg < L || tg < L) continue;
        P[M].ID = id;
        P[M].T_Grade = tg;
        P[M].V_Grade = vg;
        if (vg >= H && tg >= H) {
            P[M].G = 4;
        } else if (vg >= H) {
            P[M].G = 3;
        } else if (vg < H && tg < H && vg >= tg) {
            P[M].G = 2;
        } else {
            P[M].G = 1;
        }
        M++;
    }
    sort(P, P + M);
    
    printf("%d\n", M);
    for (i = 0; i < M; i++) {
        printf("%08lld %d %d\n", P[i].ID, P[i].V_Grade, P[i].T_Grade);
    }
    
    return 0;
} 
