#include <stdio.h>
#include <string.h>

#define MAXSIZE 100100

int main() {
    int N, schools[MAXSIZE];
    int sno, score, maxscore, msno;
    
    maxscore = 0, msno = 0;
    memset(schools, 0, sizeof(schools));
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &sno, &score);
        schools[sno] += score;
        if (schools[sno] > maxscore) {
            maxscore = schools[sno];
            msno = sno;
        }
    }
    
    printf("%d %d\n", msno, maxscore);
    return 0;
}
