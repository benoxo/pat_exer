#include "stdio.h"
#include "string.h" 

typedef struct {
    char Name[20];
    char Pwd[20];
    int Modify = 0;
} User;

int main() {
    User users[1010];
    int N, i, counter, len, j;
    char used[] = {'1', '0', 'l', 'O'}, replaced[] = {'@', '%', 'L', 'o'};
    
    scanf("%d", &N);
    i = 0;
    counter = 0;
    while (i < N) {
        scanf("%s %s", &users[i].Name, &users[i].Pwd);
        len = strlen(users[i].Pwd);
        while (len--) {
            for (j = 0; j < 4; j++) {
                if (users[i].Pwd[len] == used[j]) {
                    users[i].Modify = 1;
                    users[i].Pwd[len] = replaced[j]; 
                    break;
                }
            }
        }
        if (users[i].Modify) counter++;
        i++;
    }
    
    if (counter) {
        printf("%d\n", counter);
        for (i = 0; i < N; i++) {
            if (users[i].Modify) {
                printf("%s %s\n", users[i].Name, users[i].Pwd);
            }
        }
    } else if (N == 1) {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", N);
    }
    
    return 0;
}
