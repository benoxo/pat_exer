#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int ll;

int main() {
    int M, N, counter;
    ll i, j;
    vector<ll> primes;
    scanf("%d %d", &M, &N);

    counter = 1, i = 3;
    primes.push_back(2);
    while (counter <= N) {
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) break;
        }
        if (j > sqrt(i)) {
            counter++;
            primes.push_back(i);
        }
        i += 2;
    }

    for (i = M; i <= N; i++) {
        printf("%lld", primes[i-1]);
        if ( (i + 1 - M) % 10 == 0) printf("\n");
        else if (i < N) printf(" ");
    }

    return 0;
}
