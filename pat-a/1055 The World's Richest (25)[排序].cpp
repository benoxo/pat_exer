#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Person {
    char Name[10];
    int Age, Worth;
    
    bool operator < (const Person b) {
        if (Worth != b.Worth) return Worth > b.Worth;
        if (Age != b.Age) return Age < b.Age;
        return strcmp(Name, b.Name) < 0; 
    }
}P[100010];

int main() {
    int N, K, M, i, j, min, max, counter;
    int A[220]; // 每个年龄段的人数
    struct Person TP; 
    
    memset(A, 0, sizeof(A));
    scanf("%d %d", &N, &K);
    counter = 0;
    for (i = 0; i < N; i++) {
        scanf("%s %d %d", TP.Name, &TP.Age, &TP.Worth);
        if (A[TP.Age] <= 100) {
            A[TP.Age]++;
            P[counter++] = TP;
        }
    }
    N = counter;
    sort(P, P + N);
    
    for (i = 0; i < K; i++) {
        scanf("%d %d %d", &M, &min, &max);
        printf("Case #%d:\n", i + 1);
        counter = 0;
        for (j = 0; j < N && counter < M; j++) {
            if (P[j].Age <= max && P[j].Age >= min) {
                printf("%s %d %d\n", P[j].Name, P[j].Age, P[j].Worth);
                counter++;
            }
        }
        if (counter == 0) {
            printf("None\n");
        }
    }
    
    return 0; 
} 
