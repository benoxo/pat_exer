#include "stdio.h"
#include "string.h"

int index(char c) {
    if (c == 'B') return 0;
    if (c == 'C') return 1;
    if (c == 'J') return 2;
}

int main() {
    int N, Awin, Bwin, tie, Ause_in_win[3], Buse_in_win[3];
    int i, Awidx, Bwidx;
    char A, B, gesture[] = {'B', 'C', 'J'};
    
    scanf("%d\n", &N);
    Awin = Bwin = tie = 0;
    memset(Ause_in_win, 0, sizeof(Ause_in_win));
    memset(Buse_in_win, 0, sizeof(Buse_in_win));
    while( N-- ) {
        scanf("%c %c\n", &A, &B);
        if ( A == B) tie++;
        else if ( (index(A) + 1) % 3 == index(B)) {
            Awin++;
            Ause_in_win[index(A)]++;
        } else {
            Bwin++;
            Buse_in_win[index(B)]++;
        }
    }
    printf("%d %d %d\n", Awin, tie, Bwin);
    printf("%d %d %d\n", Bwin, tie, Awin);
    Awidx = Bwidx = 0;
    for (i = 1; i < 3; i++) {
        if (Ause_in_win[i] > Ause_in_win[Awidx]) Awidx = i;
        if (Buse_in_win[i] > Buse_in_win[Bwidx]) Bwidx = i;
    }
    printf("%c %c", gesture[Awidx], gesture[Bwidx]);

    return 0;
} 
