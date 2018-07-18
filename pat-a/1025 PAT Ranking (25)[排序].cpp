#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct Tee{
    char Id[15];
    int Score;
    int Local;
    int Trank, Lrank;
    
    bool operator < (const Tee b) {
        if (Score != b.Score) {
            return Score > b.Score;
        } else {
            return strcmp(Id, b.Id) < 0;
        }
    }
}Testee;

int main() {
    int N, K, i, j, counter, begin, end, rank;
    Testee T[30010];
    
    scanf("%d", &N);
    counter = 0;
    
    for (i = 0; i < N; i++) {
        scanf("%d", &K);
        begin = counter;
        for (j = 0; j < K; j++) {
            scanf("%s %d", T[counter].Id, &T[counter].Score);
            T[counter].Local = i+1;
            counter++;
        }
        end = counter;
        sort(T + begin, T + end);
        
        rank = 1;
        T[begin].Lrank = 1; 
        for (j = begin + 1; j < end; j++) {
            if (T[j].Score != T[j-1].Score) {
                rank = j - begin + 1;
            }
            T[j].Lrank = rank;
        }
    }
    
    sort(T, T + counter);
    rank = 1;
    T[0].Trank = 1; 
    for (i = 1; i < counter; i++) {
        if (T[i].Score != T[i-1].Score) {
            rank = i + 1;
        }
        T[i].Trank = rank;
    }
    
    printf("%d\n", counter);
    for (i = 0; i < counter; i++) {
        printf("%s %d %d %d\n", T[i].Id, T[i].Trank, T[i].Local, T[i].Lrank);
    }
    
    return 0;
} 
