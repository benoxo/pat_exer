#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

typedef struct P {
    int Scores[4] = {0, 0, 0, 0};
} *Person;

int main() {
    int RS[4][110]; 
    map<int, Person> MP;
    Person tP;
    int N, M, i, id, mrank, mcourse, j;
    char Course[] = {'A', 'C', 'M', 'E'};
    
    for (i = 0; i < 4; i++) {
        memset(RS[i], 0, sizeof(RS[i]));
    }
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++) {
        tP = (Person) malloc (sizeof(struct P));
        scanf("%d %d %d %d", &id, tP->Scores+1, tP->Scores+2, tP->Scores+3);
        tP->Scores[0] = (tP->Scores[1] + tP->Scores[2] + tP->Scores[3]) / 3;
        MP[id] = tP;
        for (j = 0; j < 4; j++) {
            RS[j][tP->Scores[j]]++;
        }
    }
    
    for (i = 100; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            RS[j][i] += RS[j][i+1];
        }
    }
    
    for (i = 0; i < M; i++) {
        scanf("%d", &id);
        if (MP.find(id) == MP.end()) {
            printf("N/A\n"); continue;
        }
        
        tP = MP.find(id)->second;
        mrank = RS[0][ tP->Scores[0] + 1 ] + 1;
        mcourse = 0;
        for (j = 1; j < 4; j++) {
            if (RS[j][ tP->Scores[j] + 1 ] + 1 < mrank) {
                mrank = RS[j][ tP->Scores[j] + 1 ] + 1;
                mcourse = j;
            }
        }
        printf("%d %c\n", mrank, Course[mcourse]);
    } 
    
    return 0;
}
