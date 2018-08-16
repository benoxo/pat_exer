#include <cstdio>

int main() {
    int N, pre, next;
    long long int totalTime;
    scanf("%d", &N);
    totalTime = 0;
    pre = 0;
    while (N--) {
        scanf("%d", &next);
        if (next - pre > 0) {
            totalTime += (next - pre) * 6 + 5;
        } else {
            totalTime += (pre - next) * 4 + 5;
        }
        pre = next;
    }
    printf("%lld", totalTime);
    return 0;
}
