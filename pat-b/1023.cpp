#include <cstdio>
#include <cstring>

int main() {
    int HT[10], i, d;

    memset(HT, 0, sizeof(HT));
    for (i = 0; i < 10; i++) {
        scanf("%d", &d);
        HT[i] = d;
    }

    for (i = 1; i < 10; i++) {
        if (HT[i] > 0) {
            printf("%d", i);
            HT[i]--;
            break;
        }
    }

    for (i = 0; i < 10; i++) {
        while (HT[i]--) {
            printf("%d", i);
        }
    }

    return 0;
}
