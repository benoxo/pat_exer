#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, i;
    double A, sum;
    scanf("%d", &N);
    sum = 0;
    for (i = 0; i < N; i++) {
        scanf("%lf", &A);
        sum += A * (N - i) * (i + 1);
    }

    printf("%.2lf\n", sum);

    return 0;
}
