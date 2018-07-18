#include "stdio.h"
#include "string.h"

int main() {
    //freopen("1082.in", "r", stdin);
    //freopen("1082.out", "w", stdout);
    char Num[][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char D[][20] = {"", " Shi", " Bai", " Qian", " Wan", " Shi", " Bai", " Qian", " Yi"};
    char Nstr[200];
    long long N; 
    int i, len, zeros, a, d;
    
    scanf("%lld", &N);
    if (N < 0) {
        N = -N;
        printf("Fu ");
    }
    sprintf(Nstr, "%lld", N);
    len = strlen(Nstr);
    zeros = 0;
    printf("%s%s", Num[ Nstr[0] - '0' ], D[ len - 1 ]);
    for (i = 1; i < len; i++) {
        a = Nstr[i] - '0';
        d = len - i - 1;
        if (a) {
            printf(" %s%s", Num[ a ], D[ d ]);
            zeros = 0;
        } else {
            zeros++;
            if (d % 4 == 0 && zeros < 4) {
                printf("%s", D[ d ]);
                zeros = 0;
            } else if (d > 0 && Nstr[i + 1] != '0') {
                printf(" ling");
                zeros = 0;
            }
        }

    }
    
    return 0;
} 
