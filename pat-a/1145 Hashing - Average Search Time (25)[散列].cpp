#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

bool IsPrime(int K) {
    if (K < 2) return false;
    for (int i = 2; i <= sqrt(K); i++) {
        if (K % i == 0) {
            return false;
        }
    }
    return true;
}

int NextPrime(int K) {
    while (!IsPrime(K)) K++;
    return K;
}

int Table[100100], Size;

int Hash(int K) {
    return K % Size;
}

void Insert(int K) {
    int M = 0;
    int H = Hash(K);
    while (Table[H] != -1 && M < Size) {
        H = Hash(H + 2*M + 1);
        M++;
    }
    if (M < Size) {
        Table[H] = K;
    } else {
        cout << K << " cannot be inserted.\n";
    }
}

int Search(int K) {
    int M = 0;
    int H = Hash(K);
    while (Table[H] != -1 && Table[H] != K && M < Size) {
        H = Hash(H + 2*M + 1);
        M++;
    }
    return M+1;
}

int main() {
    int MSize, N, M, K, STime;

    cin >> MSize >> N >> M;
    Size = NextPrime(MSize);

    memset(Table, -1, sizeof(Table));
    for (int i = 0; i < N; i++) {
        cin >> K;
        Insert(K);
    }

    STime = 0;
    for (int i = 0; i < M; i++) {
        cin >> K;
        STime += Search(K);
    }
    printf("%.1lf", STime*1.0/M);

    return 0;
}
