#include <cstdio>
#include <cstring>

int main() {
    int ins[100010], HashTable[10010], N, i, d;
    
    memset(HashTable, 0, sizeof(HashTable));
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", ins + i);
        HashTable[ins[i]]++;
    }
    
    for (i = 0; i < N; i++) {
        d = ins[i];
        if (HashTable[d] == 1) {
            printf("%d", d);
            break;
        }
    }
    if (i == N) {
        printf("None\n");
    }
    
    return 0;
} 
