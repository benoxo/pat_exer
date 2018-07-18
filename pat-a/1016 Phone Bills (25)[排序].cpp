#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Record {
    char Name[30];
    int M, D, H, Min, F;
    
    bool operator < (const Record b) {
        int Nc = strcmp(Name, b.Name);
        if (Nc != 0) {
            return Nc < 0;
        } else if ( D != b.D ) {
            return D < b.D;
        } else if ( H != b.H ) {
            return H < b.H;
        } else {
            return Min < b.Min;
        }
    }
} R[1010];

int main() {
    freopen("1016.in", "r", stdin);
    int N, i, j, rates[24];
    char flag[10], tR[30];
    int total, tmpcost;
    Record R1, R2;
    
    for (i = 0; i < 24; i++) {
        scanf("%d", rates + i);
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s %d:%d:%d:%d %s", R[i].Name, &R[i].M, &R[i].D, &R[i].H, &R[i].Min, flag);
        if (flag[1] == 'n') {
            R[i].F = 0;
        } else {
            R[i].F = 1;
        }
    }
    sort(R, R + N);
    
    total = 0;
    for (i = 0; i < N ; i++) {
        while (i < N && R[i].F != 0) i++;
        while (i < N && R[i].F == 0) i++;
        if (i >= N) break;
        i--;
        R1 = R[i];
        
        while (i < N && strcmp(R[i].Name, R1.Name) == 0 && R[i].F != 1) i++;
        if (i >= N || strcmp(R[i].Name, R1.Name) != 0) {
            i--; 
            continue;
        }
        R2 = R[i];
        
        if (strcmp(R1.Name, tR) != 0) {
            if (total != 0) printf("Total amount: $%.2lf\n", total/100.0);
            printf("%s %02d\n", R1.Name, R1.M);
            strcpy(tR, R1.Name);
            total = 0;
        }
        
        printf("%02d:%02d:%02d %02d:%02d:%02d ", R1.D, R1.H, R1.Min, R2.D, R2.H, R2.Min);
        R1.H += R1.D * 24;
        R2.H += R2.D * 24;
        if (R1.H == R2.H) {
            tmpcost = (R2.Min - R1.Min) * rates[R1.H % 24];
        } else {
            tmpcost = (60 - R1.Min) * rates[R1.H % 24]; 
            for (j = R1.H + 1; j < R2.H; j++) {
                tmpcost += 60 * rates[j % 24];
            }
            tmpcost += R2.Min * rates[R2.H % 24];
        }
        R1.Min += R1.H * 60;
        R2.Min += R2.H * 60;
        printf("%d $%.2lf\n", R2.Min - R1.Min, tmpcost/100.0);
        total += tmpcost;
    }
    printf("Total amount: $%.2lf\n", total/100.0);
    
    return 0;
}
