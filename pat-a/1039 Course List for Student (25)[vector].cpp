#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int NameToId(char Name[]) {
    int id = (Name[0]-'A')*26*26*10 + (Name[1]-'A')*26*10
            + (Name[2]-'A')*10 + Name[3]-'0';
    return id;
}

int main() {
    int N, K, Index, Ni, i, j, Id;
    char Name[5];
    vector<int> S[26*26*26*10+1];

    scanf("%d %d", &N, &K);
    for (i = 0; i < K; i++) {
        scanf("%d %d", &Index, &Ni);
        for (j = 0; j < Ni; j++) {
            scanf("%s", Name);
            S[NameToId(Name)].push_back(Index);
        }
    }

    for (i = 0; i < N; i++) {
        scanf("%s", Name);
        Id = NameToId(Name);
        printf("%s %d", Name, S[Id].size());
        sort(S[Id].begin(), S[Id].end());
        vector<int>::iterator it = S[Id].begin();
        while (it != S[Id].end()) {
            printf(" %d", *it);
            it++;
        }
        printf("\n");
    }
    return 0;
}
