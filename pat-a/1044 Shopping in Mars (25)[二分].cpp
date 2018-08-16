#include <cstdio>
#include <vector>
#define INF 65535
using namespace std;

int main() {
    int N, payment, dimonds[100010], i, j, mount, solution, minimize;
    vector<int> minstart;
    vector<int> minend;

    scanf("%d %d", &N, &payment);
    for (i = 0; i < N; i++) {
        scanf("%d", dimonds + i);
    }

    i= 0, mount = 0, j = 0, solution = 0, minimize = INF;
    while (i < N) {
        while (mount < payment && j < N) {
            mount += dimonds[j++];
        }
        if (mount == payment) {
            printf("%d-%d\n", i+1, j);
            solution = 1;
        } else if (mount > payment && !solution) {
            if (mount < minimize) {
                minstart.clear();
                minend.clear();
                minstart.push_back(i+1);
                minend.push_back(j);
                minimize = mount;
            } else if (mount == minimize) {
                minstart.push_back(i+1);
                minend.push_back(j);
            }
        }
        mount -= dimonds[i++];
    }

    if (!solution) {
        for (i = 0; i < minstart.size(); i++) {
            printf("%d-%d\n", minstart.at(i), minend.at(i));
        }
    }
    return 0;
}

