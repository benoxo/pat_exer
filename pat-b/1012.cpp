#include "stdio.h"

int main() {
    int a1, a2, a2sign, a2exist, a3, a4, a4count, a5, tmp;
    int count;

    scanf("%d", &count);
    a1 = a2 = a3 = a4 = a4count = a5 = 0;
    a2sign = 1;
    a2exist = 0;

    while (count--) {
        scanf("%d", &tmp);
        switch (tmp % 5) {
        case 0: if (tmp % 2 == 0)
                    a1 += tmp;
                break;
        case 1: a2exist = 1;
                a2 += a2sign * tmp;
                a2sign = -a2sign;
                break;
        case 2: a3++;
                break;
        case 3: a4 += tmp;
                a4count++;
                break;
        case 4: if (a5 < tmp)
                    a5 = tmp;
        }
    }

    a1 > 0 ? printf("%d ", a1) : printf("N ");
    a2exist > 0 ? printf("%d ", a2) : printf("N ");
    a3 > 0 ? printf("%d ", a3) : printf("N ");
    a4 > 0 ? printf("%.1f ", a4*1.0/a4count) : printf("N ");
    a5 > 0 ? printf("%d", a5) : printf("N");

    return 0;
}

