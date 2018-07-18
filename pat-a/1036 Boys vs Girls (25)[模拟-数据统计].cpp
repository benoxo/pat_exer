#include "stdio.h"
#include "string.h"

struct Stu {
    char Name[20];
    char Id[20];
}F, M;
int main() {
    int largest, lowest, N, i, grade;
    char name[20], id[20], gender;
    
    scanf("%d", &N);
    largest = -1;
    lowest = 101;
    
    for (i = 0; i < N; i++) {
        scanf("%s %c %s %d", name, &gender, id, &grade);
        if (gender == 'F' && grade > largest) {
            largest = grade;
            strcpy(F.Name, name);
            strcpy(F.Id, id);
        }
        if (gender == 'M' && grade < lowest) {
            lowest = grade;
            strcpy(M.Name, name);
            strcpy(M.Id, id);
        } 
    }
    
    if (largest > -1 && lowest < 101) {
        printf("%s %s\n%s %s\n%d", F.Name, F.Id, M.Name, M.Id, largest - lowest);
    } else {
        if (largest > -1) {
            printf("%s %s\n", F.Name, F.Id);
        } else {
            printf("Absent\n");
        }
        if (lowest < 101) {
            printf("%s %s\n", M.Name, M.Id);
        } else {
            printf("Absent\n");
        }
        printf("NA\n");
    } 
    
    return 0; 
}
