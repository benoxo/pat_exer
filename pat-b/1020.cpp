#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct mooncake {
    double quantity;
    double price;
    bool operator < (const mooncake b) {
        return price / quantity > b.price / b.quantity;
    }
} MK[1010];

int main() {
    int N, i, D;
    double profit;


    scanf("%d %d", &N, &D);
    for (i = 0; i < N; i++) {
        scanf("%lf", &MK[i].quantity);
    }
    for (i = 0; i < N; i++) {
        scanf("%lf", &MK[i].price);
    }

    profit = 0;
    sort(MK, MK + N);
    for (i = 0; i < N && D > 0; i++) {
        if (D >= MK[i].quantity) {
            D -= MK[i].quantity;
            profit += MK[i].price;
        } else {
            profit += MK[i].price / MK[i].quantity * D;
            D = 0;
        }
    }
    printf("%.2lf", profit);
    return 0;
}
