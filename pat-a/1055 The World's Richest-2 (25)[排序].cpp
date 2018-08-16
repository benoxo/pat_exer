#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Person {
    char Name[10];
    int Age, Worth;

    bool operator < (const Person b) {
        if (Worth != b.Worth) return Worth > b.Worth;
        if (Age != b.Age) return Age < b.Age;
        return strcmp(Name, b.Name) < 0;
    }
}P[100010];

int main() {
    int N, K, M, i, j, min, max, counter, age, CJ;
    int A[220][100], tails[220], C[220];
    struct Person candidate;

    memset(A, 0, sizeof(A));
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%s %d %d", P[i].Name, &P[i].Age, &P[i].Worth);
    }
    sort(P, P + N);

    memset(tails, 0, sizeof(tails));
    for (i = 0; i < N; i++) {
        age = P[i].Age;
        if (tails[age] < 100) {
            A[age][ tails[age]++ ] = i;
        }
    }

    for (i = 0; i < K; i++) {
        scanf("%d %d %d", &M, &min, &max);
        printf("Case #%d:\n", i + 1);
        counter = 0;
        memset(C, 0, sizeof(C));

        while (counter < M) {
            CJ = -1;
            candidate.Worth = -10000000;
            for (j = min; j <= max; j++) {
                if (C[j] < tails[j] && P[ A[j][ C[j] ] ] < candidate) {
                    candidate = P[ A[j][ C[j] ] ];
                    CJ = j;
                }
            }
            if (CJ > -1) {
                printf("%s %d %d\n", candidate.Name, candidate.Age, candidate.Worth);
                C[CJ]++;
                counter++;
            } else {
                break;
            }
        }

        if (counter == 0) {
            printf("None\n");
        }
    }

    return 0;
}

