#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct Stu {
    char Name[30];
    char ID[30];
    int Grade; 
} Student;

int main() {
    int N, i, j, GwS[110], g1, g2;
    Student S[200];
    
    scanf("%d", &N);
    memset(GwS, -1, sizeof(GwS));
    for (i = 0; i < N; i++) {
        scanf("%s %s %d", S[i].Name, S[i].ID, &S[i].Grade);
        GwS[S[i].Grade] = i;
    }
    scanf("%d %d", &g1, &g2);
    j = 0;
    for (i = g2; i >= g1; i--) {
        if (GwS[i] > -1) {
            printf("%s %s\n", S[ GwS[i] ].Name, S[ GwS[i] ].ID);
            j++;
        }
    }
    if (j == 0) {
        printf("NONE\n");
    }
    
    return 0;
}
