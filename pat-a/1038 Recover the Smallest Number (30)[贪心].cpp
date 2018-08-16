#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> datas;
int N;

bool compare(const string a, const string b);

int main() {
    cin >> N;
    datas.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> datas[i];
    }
    sort(datas.begin(), datas.end(), compare);
    
    string all;
    int s = 0;
    for (int i = 0; i < N; i++) {
        all += datas[i];
    }

    while (all[s] == '0') s++;
    if (s == all.length()) cout << 0;
    while (s != all.length()) cout << all[s++];
    return 0;
}

bool compare(string a, string b) {
    return a+b < b+a;
}
