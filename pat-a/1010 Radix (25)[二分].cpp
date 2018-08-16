#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long int CalInRadix(char N[], int radix) {
    int len = strlen(N);
    long long int V = 0, base = 1;
    for (int i = len-1; i >= 0; i--) {
        if (N[i] <= '9' && N[i] >= '0') {
            V += (N[i] - '0') * base;
        } else {
            V += (N[i] - 'a' + 10) * base;
        }
        base *= radix;
    }

    return V;
}

long long int FindRadix(char N[], long long int low, long long int high, long long int V1) {
    long long int V2, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        V2 = CalInRadix(N, mid);
        if ( V2 > V1 || V2 < 0) {
            high = mid - 1;
        } else if ( V2 < V1 ) {
            low = mid + 1;
        } else {
            break;
        }
    }
    if (V1 == V2) {
        return mid;
    } else {
        return 0;
    }
}

int MinRadix(char N[]) {
    int len = strlen(N);
    int min = 1;
    for (int i = 0; i < len; i++) {
        if (N[i] <= '9' && N[i] >= '0' && N[i] - '0' > min) {
            min = N[i] - '0';
        } else if (N[i] - 'a' + 10 > min) {
            min = N[i] - 'a' + 10;
        }
    }
    return min + 1;
}

int main() {
    int tag;
    char N1[12], N2[12];
    long long int V1, V2, radix, tradix, minradix;
    scanf("%s %s %d %lld", N1, N2, &tag, &radix);

    if (tag == 1) {
        V1 = CalInRadix(N1, radix);
        minradix = MinRadix(N2);
        tradix = FindRadix(N2, minradix, max(V1, minradix) + 1, V1);
    } else {
        V1 = CalInRadix(N2, radix);
        minradix = MinRadix(N1);
        tradix = FindRadix(N1, minradix, max(V1, minradix) + 1, V1);
    }
    if (tradix) {
        printf("%lld", tradix);
    } else {
        printf("Impossible");
    }
    return 0;
}

