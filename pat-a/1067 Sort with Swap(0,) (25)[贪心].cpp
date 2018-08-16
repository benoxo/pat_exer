#include <cstdio>
#include <cstring>

int main() {
    int N, Seq[100010], i, j, result, Sorted[100010];
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", Seq + i);    
    }
    
    result = 0;
    for (i = 1; i < N; i++) {
        if (Sorted[i]) continue;
        j = Seq[i];
        while (j != i) {
            Sorted[j] = 1;
            result += 1;
            j = Seq[j];
        }
        if (Seq[i] != i) result += 2;
    }
    if (Seq[0] != 0) result -= 2;
    printf("%d", result);
    
    return 0;
}
