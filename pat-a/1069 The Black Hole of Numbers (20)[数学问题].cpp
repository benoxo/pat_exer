#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N, N1, N2;
    char StrN[5];
    scanf("%d", &N);
    do{
        sprintf(StrN, "%04d", N);
        sort(StrN, StrN + 4);
        sscanf(StrN, "%d", &N1);
        sort(StrN, StrN + 4, greater<int>());
        sscanf(StrN, "%d", &N2);
        N = N2 - N1;
        printf("%04d - %04d = %04d\n", N2, N1, N);
    } while (N && N != 6174);

    return 0;
}
