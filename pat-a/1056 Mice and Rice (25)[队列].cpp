#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int weight;
    int rank;
} Mice;

int main() {
    int N, M, weight, id, rank, size;
    vector<Mice> Mouse;
    queue<int> contest;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        Mice mice;
        cin >> mice.weight;
        Mouse.push_back(mice);
    }
    for (int i = 0; i < N; i++) {
        cin >> id;
        contest.push(id);
    }

    int begin, end, fatest;
    while (contest.size() > 1) {
        begin = 0;
        rank = contest.size() / M + 1;
        if (contest.size() % M) rank += 1;
        size = contest.size();
        while (begin < size) {
            fatest = contest.front();
            end = begin + M > size ? size : begin + M;
            for (int i = begin; i < end; i++) {
                if (Mouse[contest.front()].weight > Mouse[fatest].weight) {
                    fatest = contest.front();
                }
                Mouse[contest.front()].rank = rank;
                contest.pop();
            }
            contest.push(fatest);
            begin += M;
        }
    }
    Mouse[contest.front()].rank = 1;

    for (int i = 0; i < N; i++) {
        printf("%d", Mouse[i].rank);
        if (i < N-1) printf(" ");
    }

    return 0;
}

