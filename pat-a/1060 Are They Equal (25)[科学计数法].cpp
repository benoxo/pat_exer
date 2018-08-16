#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void Standarize(string &S, int N, int &E) {
    while (S.size() > 0 && S[0] == '0') {
        S.erase(S.begin());
    }
    if (S[0] != '.') {
        E = S.find('.');
        if (E > 0) S.erase(S.begin() + E);
        else E = S.size();
        if (S.size() < N) {
            for (int i = S.size(); i < N; i++) {
                S.append("0");
            }
        } else {
            S.erase(S.begin() + N, S.end());
        }
    } else {
        S.erase(S.begin());
        E = 0;
        while (S.size() > 0 && S[0] == '0') {
            S.erase(S.begin());
            E--;
        }
        if (S.size() == 0) {
            E = 0;
        }

        if (S.size() > N) {
            S.erase(S.begin() + N, S.end());
        } else {
            while (S.size() < N) {
                S.append("0");
            }
        }
    }
    S.insert(0, "0.");
}

int main() {
    int N, EA, EB;
    string A, B;
    cin >> N >> A >> B;
    Standarize(A, N, EA);
    Standarize(B, N, EB);
    if (A.compare(B) == 0 && EA == EB) {
        cout << "YES " << A << "*10^" << EA << endl;
    } else {
        cout << "NO " << A << "*10^" << EA << " " << B << "*10^" << EB << endl;
    }

    return 0;
}
