#include <cstdio>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int N, M, S;
    string users[1010];
    unordered_map<string, bool> visited;

    cin >> N >> M >> S;
    getchar();
    for (int i = 0; i < N; i++) {
        cin >> users[i+1];
        visited[users[i+1]] = false;
    }

    for (int i = S; i <= N;) {
        if (!visited[users[i] ]) {
            visited[users[i]] = true;
            cout << users[i] << endl;
            i += M;
        } else {
            i ++;
        }
    }
    if (S > N) cout << "Keep going..." << endl;
    return 0;
}
