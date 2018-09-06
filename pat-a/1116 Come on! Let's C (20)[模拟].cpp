#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 10010;
int contestants[MAXN] = {0};

bool IsPrime(int N) {
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M, T;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &T);
        contestants[T] = i+1;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &T);
        printf("%04d: ", T);
        if (contestants[T] == 0) {
            printf("Are you kidding?");
        } else if (contestants[T] == -1) {
            printf("Checked");
        } else {
            if (contestants[T] == 1) {
                printf("Mystery Award");
            } else if (IsPrime(contestants[T])) {
                printf("Minion");
            } else {
                printf("Chocolate");
            }
            contestants[T] = -1;
        }
        printf("\n");
    }
    return 0;
}
