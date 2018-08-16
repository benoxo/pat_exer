#include <cstdio>
#include <algorithm>
using namespace std;

struct User {
    int Id;
    int Score[6] = {-1, -1, -1, -1, -1, -1};
    int Perfect = 0, TS = 0, Valid = 0;
    int Rank;
    
    bool operator < ( const User b) {
        if (TS != b.TS) return TS > b.TS;
        if (Perfect != b.Perfect) return Perfect > b.Perfect;
        return Id < b.Id;
    }
};

int main() {
    int N, K, M, P[6], i, j, id, tno, score;
    User U[10010];
    
    scanf("%d %d %d", &N, &K, &M);
    for (i = 1; i <= K; i++) {
        scanf("%d", P + i);
    }
    
    for (i = 0; i < M; i++) {
        scanf("%d %d %d", &id, &tno, &score);
        if (U[id].Score[tno] <= score) {
            U[id].Id = id;
            U[id].Score[tno] = score > 0 ? score : 0;
            if (score >= 0) U[id].Valid = 1;
            
        }
    }
    
    for (i = 1; i <= N; i++) {
        if (U[i].Valid == 0) continue;
        for (j = 1; j <= K; j++) {
            if (U[i].Score[j] != -1) {
                U[i].TS += U[i].Score[j];
            }
            if (U[i].Score[j] == P[j]) {
                U[i].Perfect++;
            }
        }
    }
    
    sort(U+1, U+N+1);
    for (i = 1; i <= N; i++) {
        if (U[i].Valid == 0) continue;
        if (i == 1) {
            U[i].Rank = 1;
        } else if (U[i].TS == U[i-1].TS) {
            U[i].Rank = U[i-1].Rank;
        } else {
            U[i].Rank = i;
        }
        printf("%d %05d %d", U[i].Rank, U[i].Id, U[i].TS);
        for (j = 1; j <= K; j++) {
            U[i].Score[j] > -1 ? printf(" %d", U[i].Score[j]) : printf(" -");
        }
        printf("\n");
    }
    
    return 0;
} 
