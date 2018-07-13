#include "stdio.h"
#include "stdlib.h"

typedef struct Stu {
    char no[15];
    int   seat;
}*PtrToStu;

int main() {
    PtrToStu students[1010];
    int N, tseat;
    scanf("%d", &N);
    while (N--) {
        PtrToStu s = (PtrToStu)malloc(sizeof(Stu));
        scanf("%s %d %d", s->no, &tseat, &(s->seat));
        students[tseat] = s;
    }
    
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tseat);
        printf("%s %d\n", students[tseat]->no, students[tseat]->seat);
    }
    return 0;
}
