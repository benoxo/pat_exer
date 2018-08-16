#include <cstdio>
#include <cstring>

int main() {
    int N, i, j, len, P, A, T, locP, locT, O, x, y, z;
    char str[110];

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s", str);
        len = strlen(str);
        j = 0; P = A = T = O = 0;
        for (j = 0; j < len; j++) {
            if (str[j] == 'P') {
                P++;
                locP = j;
            }
            else if (str[j] == 'A') A++;
            else if (str[j] == 'T') {
                T++;
                locT = j;
            }
            else O = 1;
        }
        if (P != 1 || !A || T != 1 || O || locP > locT) {
            printf("NO\n");
            continue;
        }

        x = y = z = 0; j = 0;
        while (str[j++] == 'A') x++;
        while (str[j++] == 'A') y++;
        while (j < len && str[j++] == 'A') z++;

        while (y > 1) {
            y--;
            z -= x;
        }
        if (y == 1 && z == x) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
