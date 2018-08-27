#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main() {
    int N, K, Sum;
    set<int> S;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        Sum = 0;
        while (K) {
            Sum += K % 10;
            K /= 10;
        }
        S.insert(Sum);
    }

    printf("%d\n", S.size());
    set<int>::iterator it = S.begin();
    while (it != S.end()) {
        printf("%d", *it);
        if (++it != S.end()) printf(" ");
    }

    return 0;
}
