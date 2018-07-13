#include <stdio.h>

int main() {
    int Len, Width, C;
    
    Len = 0;
    scanf("%d %c", &Len, &C);
    Width = Len % 2 ? Len/2 + 1 : Len/2;
    
    for (int i = 0; i < Len; i++) {
        printf("%c", C);
    } 
    printf("\n");
    
    for (int i = 0; i < Width-2; i++) {
        printf("%c", C);
        for (int j = 0; j < Len-2; j++) {
            printf(" ");
        }
        printf("%c", C);
        printf("\n");
    }
    
    for (int i = 0; i < Len; i++) {
        printf("%c", C);
    } 
    printf("\n");
    
    return 0;
}
