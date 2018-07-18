#include "stdio.h"

int main() {
    char in[20000];
    int exp, i, end, dindex;
    
    scanf("%s", in);
    i = 0;
    while (in[i] != 'E') i++;
    end = i;
    sscanf(in+i+1, "%d", &exp);
    
    if (in[0] == '-') 
        printf("-");
    if (exp >= 0) {
        dindex = exp + 2;
        printf("%c", in[1]);
        i = 3;
        while (i < end) {
            if (i-1 == dindex) {
                printf(".");
            }
            printf("%c", in[i]);
            i++;
        }
        while (end < dindex + 1) {
            printf("0");
            end++;
        }
    } else {
        printf("0.");
        while (++exp) {
            printf("0");
        }
        printf("%c", in[1]);
        i = 3;
        while (i < end) {
            printf("%c", in[i]);
            i++;
        }
    }
    return 0;
}
