#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

typedef struct S {
    string Name;
    int Height;
    bool operator < (const S b) {
        if (Height != b.Height) return Height > b.Height;
        return Name < b.Name;
    }
} Stu;

Stu Students[10010];

void HandleRow(int begin, int end) {
    deque<Stu> row;
    row.push_back(Students[begin]);
    int handle = begin + 1;
    int i = 1;
    while (handle < end) {
        if (handle < end) row.push_front(Students[ handle++ ]);
        if (handle < end) row.push_back(Students[ handle++ ]);
    }

    while (!row.empty()) {
        cout << row.front().Name;
        row.pop_front();
        if (!row.empty()) printf(" ");
    }
    cout << endl;
}

int main() {
    int N, K;
    int first;

    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        cin >> Students[i].Name >> Students[i].Height;
    }
    sort(Students, Students + N);

    int lastRowNum = N - N/K * (K-1);
    HandleRow(0, lastRowNum);
    first = lastRowNum;
    while (first < N) {
        HandleRow(first, first + N/K);
        first += N/K;
    }
    return 0;
}
