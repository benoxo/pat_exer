#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char Name[40010][5];
vector<int> course[2501];

bool cmp(int a, int b) {
    return strcmp(Name[a], Name[b]) < 0;
};

int main() {
    int N, K, C, i, j, Id;

    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%s %d", Name[i], &C);
        for (j = 0; j < C; j++) {
            scanf("%d", &Id);
            course[Id].push_back(i);
        }
    }

    for (i = 1; i <= K; i++) {
        sort(course[i].begin(), course[i].end(), cmp);
        printf("%d %d\n", i, course[i].size());
        for (j = 0; j < course[i].size(); j++) {
            printf("%s\n", Name[course[i][j]]);
        }
    }
    
    // 最后一组数据一直超时 

    return 0;
}
