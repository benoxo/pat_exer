#include "stdio.h"

typedef struct Stu {
    char Name[20];
    char Sno[20];
    int score;
} Stu;

int main() {
    Stu students[105];
    int highest, lowest, hno, lno, N, i;
    highest = 1;
    lowest = 101;
    hno = lno = 0;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s %s %d", students[i].Name, students[i].Sno, &students[i].score);
        if (students[i].score > highest) {
            highest = students[i].score;
            hno = i;
        }
        if (students[i].score < lowest) {
            lowest = students[i].score;
            lno = i;
        }
    }
    
    printf("%s %s\n", students[hno].Name, students[hno].Sno);
    printf("%s %s\n", students[lno].Name, students[lno].Sno);
    
    return 0;
}
