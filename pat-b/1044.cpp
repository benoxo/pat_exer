#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <iostream>
#include <string>
using namespace std;

map<string, int> ToEarth;
string ToMars[200];

string unitDigit[] = {"tret", "jan", "feb", "mar", "apr", "may",
                      "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[] = {"tret", "tam", "hel", "maa", "huh", "tou",
                      "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void init() {
    ToMars[0] = "tret";
    ToEarth["tret"] = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (i > 0) ToMars[i*13 + j] += tenDigit[i];
            if (i > 0 && j > 0) ToMars[i*13 + j] += " ";
            if (j > 0) ToMars[i*13 + j] += unitDigit[j];

            ToEarth[ ToMars[i*13 + j] ] = i*13 + j;
        }
    }
}

int main() {
    string num;
    int N, i, Nb;

    init();

    scanf("%d\n", &N);
    for (i = 0; i < N; i++) {
        getline(cin, num);
        if (isdigit(num[0])) {
            Nb = stoi(num);
            cout << ToMars[Nb] << endl;
        } else {
            cout <<  ToEarth[num] << endl;
        }
    }

    return 0;
}
