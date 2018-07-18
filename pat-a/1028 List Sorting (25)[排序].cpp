#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N, C, i;

typedef struct Stu {
    int Id;
    char Name[10];
    int Score;
    
    bool operator < (const Stu b) {
        if (C == 1) return Id < b.Id;
        int cmp = strcmp(Name, b.Name);
        if (C == 2) return cmp == 0 ? Id < b.Id : cmp < 0;
        if (C == 3) return Score == b.Score ? Id < b.Id : Score < b.Score;
    }
} Student;
Student S[100010]; 
    
int main() {
    
    scanf("%d %d", &N, &C);
    for (i = 0; i < N; i++) {
        scanf("%d %s %d", &S[i].Id, S[i].Name, &S[i].Score);
    }
    sort(S, S + N);
    
    for (i = 0; i < N; i++) {
        printf("%06d %s %d\n", S[i].Id, S[i].Name, S[i].Score);
    }
    
    return 0;
}
