#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 40010

struct Student {
    int ID, GE, GI, T, Prefer[5];
    bool operator < (const Student b) {
        if (T != b.T) return T > b.T;
        return GE > b.GE;
    } 
    bool operator == (const Student b) {
        return T == b.T && GE == b.GE;
    }
} Stu[MAXN]; 

typedef struct Ad {
    struct Student *Stu;
    bool operator < (const Ad b) {
        return Stu->ID < b.Stu->ID;
    }
} Admission;

struct School {
    int Quta, AdNum;
    Student *Last;
    Admission Admits[MAXN];
} Sch[110];

int N, M, K, i, j, prefer;

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (i = 0; i < M; i++) {
        scanf("%d", &Sch[i].Quta);
    }
    
    for (i = 0; i < N; i++) {
        scanf("%d %d", &Stu[i].GE, &Stu[i].GI);
        Stu[i].ID = i;
        Stu[i].T = Stu[i].GE + Stu[i].GI;
        for (j = 0; j < K; j++) {
            scanf("%d", &Stu[i].Prefer[j]);
        }
    }
    
    sort(Stu, Stu + N);
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
            prefer = Stu[i].Prefer[j];
            if (Sch[prefer].Quta > 0 || (Sch[prefer].Last != NULL && *Sch[prefer].Last == Stu[i]) ){
                Sch[ prefer ].Admits[ Sch[ prefer ].AdNum++ ].Stu = &Stu[i];
                Sch[ prefer ].Quta--;
                Sch[ prefer ].Last = &Stu[i];
                break;
            }
        }
    }
    
    for (i = 0; i < M; i++) {
        sort(Sch[i].Admits, Sch[i].Admits + Sch[i].AdNum);
        for (j = 0; j < Sch[i].AdNum; j++) {
            if (j != 0) printf(" ");
            printf("%d", Sch[i].Admits[j].Stu->ID);
        }
        printf("\n");
    }
    
    return 0;
}
