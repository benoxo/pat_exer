#include <cstdio>
#include <cctype>
#include <map>
#include <string>
using namespace std;


int main() {
    map<string, int> words;
    string s;
    string domain;
    int maxtime;
    char c;

    maxtime = 0;
    while (scanf("%c", &c) != EOF) {
        if (isalnum(c)) {
            if (isupper(c)) {
                s += c + 32;
            } else {
                s += c;
            }
        } else if (s.size() > 0) {
            if (words.find(s) != words.end()) {
                words[s]++;
            } else {
                words[s] = 1;
            }
            if (words[s] > maxtime || (words[s] == maxtime && s.compare(domain) < 0)) {
                maxtime = words[s];
                domain = s;
            }
            s.clear();
        }
    }

    printf("%s %d", domain.c_str(), maxtime);

    return 0;
}
