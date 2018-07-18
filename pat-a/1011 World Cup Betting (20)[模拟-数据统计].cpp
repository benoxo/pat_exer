#include "stdio.h"

int main() {
    int bc[3], i, j, choose;
    double profit, odds[3], lodd;
    char Choice[3] = {'W', 'T', 'L'};
    
    profit = 0.65;
    for (i = 0; i < 3; i++) {
        scanf("%lf %lf %lf", odds, odds+1, odds+2);
        lodd = -1;
        for (j = 0; j < 3; j++) {
            if (odds[j] > lodd) {
                lodd = odds[j];
                choose = j;
            }
        }
        bc[i] = choose;
        profit = profit*lodd;
    }
    
    profit = (profit-1)*2;
    printf("%c %c %c %.2lf", Choice[bc[0]], Choice[bc[1]], Choice[bc[2]], profit);
    
    return 0;
}
