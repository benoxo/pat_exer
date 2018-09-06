#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> A, B;
    int D, N;

    cin >> D >> N;
    A.push_back(D);
    while (--N) {
        B.clear();
        for (int start = 0; start < A.size();) {
            int end = start + 1;
            while (end < A.size() && A[end-1] == A[end]) end++;
            B.push_back(A[end-1]);
            B.push_back(end-start);
            start = end;
        }
        A = B;
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }
    return 0;
}
