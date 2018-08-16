#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

struct Record {
    char Plate[10];
    int H, M, S, T, flag;

    bool operator < (const Record b) {
        return T < b.T;
    }
}R[10010];

bool CmpByPlate(Record a, Record b) {
    int cmp = strcmp(a.Plate, b.Plate);
    if (cmp != 0) {
        return cmp < 0;
    } else {
        return a.T < b.T;
    }
}

int main() {
    int N, K, i, j, h, m, s, T, PC, MPT;
    char flag[5];
    map<string, int> PTmap;

    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%s %d:%d:%d %s", R[i].Plate, &R[i].H, &R[i].M, &R[i].S, flag);
        R[i].T = R[i].H * 3600 + R[i].M * 60 + R[i].S;
        if (flag[1] == 'n') {
            R[i].flag = 0;
        } else {
            R[i].flag = 1;
        }
    }

    sort(R, R + N, CmpByPlate);

    MPT = 0;
    for (i = 0; i < N - 1; i++) {
        if (strcmp(R[i].Plate, R[i+1].Plate) == 0
            && R[i].flag == 0 && R[i+1].flag == 1) {
            if (PTmap.find(R[i].Plate) == PTmap.end()) {
                PTmap[ R[i].Plate ] = 0;
            }
            PTmap[R[i].Plate] += R[i+1].T - R[i].T;
            if (PTmap[R[i].Plate] > MPT) {
                MPT = PTmap[R[i].Plate];
            }
            i += 1;
        } else {
            R[i].flag = -1;
        }

    }
    if (i == N - 1) R[i].flag = -1;

    sort(R, R + N);
    j = 0;
    PC = 0;
    for (i = 0; i < K; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        T = h * 3600 + m * 60 + s;
        for (; j < N && R[j].T <= T; j++) {
            if (R[j].flag == 0) PC++;
            else if (R[j].flag == 1) PC--;
        }
        printf("%d\n", PC);
    }

    map<string, int>::iterator it = PTmap.begin();
    while (it != PTmap.end()) {
        if (it->second == MPT) {
            printf("%s ", it->first.c_str());
        }
        it++;
    }
    printf("%02d:%02d:%02d", MPT / 3600, MPT / 60 % 60, MPT % 60);

    return 0;
}

