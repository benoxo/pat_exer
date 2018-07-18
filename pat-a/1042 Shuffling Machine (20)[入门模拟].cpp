#include "stdio.h"
#include "stdlib.h"

int *cards, N, orders[54], *tmp;

void shuffle() {
    int i, *tt;
    for (i = 0; i < 54; i++) {
        tmp[orders[i]] = cards[i+1];
    }
    tt = cards;
    cards = tmp;
    tmp = tt;
}

int main() {
    
    int i, j;
    char suits[] = {'S', 'H', 'C', 'D', 'J'};
    cards = (int*)malloc( 55 * sizeof(int) );
    tmp = (int*)malloc( 55 * sizeof(int) );
    
    scanf("%d", &N);
    for (i = 0; i < 4; i++) {
        for (j = 1; j <= 13; j++) {
            cards[i*13 + j] = i*100 + j;
        }
    }
    cards[53] = 4*100 + 1;
    cards[54] = 4*100 + 2;
    
    for (i = 0; i < 54; i++) {
        scanf("%d", orders+i);
    }
    
    while (N--) {
        shuffle();
    }
    
    for (int i = 1; i < 55; i++) {
        printf("%c%d", suits[cards[i]/100], cards[i]%100);
        if (i < 54) printf(" ");
    }
    
    return 0;
}
