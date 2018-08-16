#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;
#define INF 10000000

struct Station {
    double D, P;
    bool operator < (const Station b) {
        if ( D != b.D ) return D < b.D;
        else return P < b.P;
    }
} S[510];

int main() {
    double Cmax, D, Davg, Dmax, minP, totalfee, C, Cneed;
    int i, N, now, next;
    
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &N);
    Dmax = Davg * Cmax;
    for (i = 0; i < N; i++) {
        scanf("%lf %lf", &S[i].P, &S[i].D);
    }
    S[N].D = D;
    S[N].P = 0;
    sort(S, S + N);
    
    if (S[0].D > 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    
    now = 0;
    C = 0;
    totalfee = 0;
    while (now < N) {
        minP = INF;
        next = 0;
        for (i = now+1; i <= N && S[i].D - S[now].D <= Dmax; i++) {
            if (S[i].P < minP) {
                minP = S[i].P;
                next = i;
                if (minP < S[now].P) {
                    break;
                }
            }
        }
        
        if (!next) break;
        Cneed = (S[next].D - S[now].D) / Davg;
        if (S[next].P <= S[now].P) {
            if (C >= Cneed) {
                C -= Cneed;
            } else {
                totalfee += (Cneed - C) * S[now].P;
                C = 0;
            }
        } else {
            totalfee += (Cmax - C) * S[now].P;
            C = Cmax - Cneed;
        }
        now = next;
    }
    
    if (now < N) {
        printf("The maximum travel distance = %.2lf", S[now].D + Cmax * Davg);
    } else {
        printf("%.2lf", totalfee);
    }
    
    return 0;
} 
