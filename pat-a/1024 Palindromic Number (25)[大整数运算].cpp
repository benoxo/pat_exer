#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool IsPali(int Nstr[], int len) {
    int i;
    for (i = 0; i < len/2; i++) {
        if (Nstr[i] != Nstr[len - i - 1]) return false;
    }
    return true;
};

int main() {
    int N[1010], NR[1010];
    int K, step, i, len;
    char Nstr[1010];

    memset(N, 0, sizeof(N));
    memset(NR, 0, sizeof(NR));

    scanf("%s %d", Nstr, &K);
    len = strlen(Nstr);
    for (i = 0; i < len; i++) {
        N[i] = Nstr[i] - '0';
    }

    step = 0;
    while (!IsPali(N, len) && step < K){
        reverse_copy(N, N + len, NR);
        for (i = 0; i < len; i++) { // N + NR
            N[i] += NR[i];
            N[i + 1] += N[i] / 10;
            N[i] %= 10;
        }
        if (N[i] != 0) len++;
        step++;
    }

    for (i = len; i > 0; i--) {
        printf("%d", N[i-1]);
    }
    printf("\n%d", step);

    return 0;
}
