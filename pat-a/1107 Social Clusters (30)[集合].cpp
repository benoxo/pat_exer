#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int Set[1010];
int HeadOfCourse[1010];
vector<int> ClusterSize;

int FindRoot(int T) {
    if (Set[T] < 0) return T;
    return Set[T] = FindRoot(Set[T]);
}

int Union(int A, int B) {
    int RootA = FindRoot(A);
    int RootB = FindRoot(B);
    if (RootA != RootB) {
        Set[RootB] += Set[RootA];
        Set[RootA] = RootB;
    }
}

int main() {
    int N, K, ID;
    scanf("%d", &N);

    memset(Set, -1, sizeof(Set));
    memset(HeadOfCourse, 0 , sizeof(HeadOfCourse));
    for (int i = 1; i <= N; i++) {
        scanf("%d:", &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &ID);
            if (HeadOfCourse[ID] == 0) {
                HeadOfCourse[ID] = i;
            } else {
                Union(HeadOfCourse[ID], i);
            }
        }
    }


    for (int i = 1; i <= N; i++) {
        if (Set[i] < 0) {
            ClusterSize.push_back(-Set[i]);
        }
    }
    sort(ClusterSize.begin(), ClusterSize.end(), greater<int>());

    printf("%d\n", ClusterSize.size());
    for (int i = 0; i < ClusterSize.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", ClusterSize[i]);
    }
    return 0;
}
