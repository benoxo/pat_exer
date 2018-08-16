#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    string id, author, title, keyword, key, publisher, publishedYear;
    map<string, vector<string> > Query[5];// Authors, Titles, Keys, Pubrs, PubYears;
    int N, kase, size;
    string qstr;

    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keyword);
        getline(cin, publisher);
        getline(cin, publishedYear);
        Query[0][title].push_back(id);
        Query[1][author].push_back(id);
        for (int j = 0; j <= keyword.size(); j++) {
            if (j < keyword.size() && keyword[j] != ' ') {
                key.push_back(keyword[j]);
            } else {
                Query[2][key].push_back(id);
                key.clear();
            }
        }
        Query[3][publisher].push_back(id);
        Query[4][publishedYear].push_back(id);
    }

    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        getline(cin, qstr);
        kase = qstr[0] - '0';
        cout << qstr << endl;
        qstr.erase(qstr.begin(), qstr.begin() + 3);
        if (Query[kase-1].find(qstr) == Query[kase-1].end() ) {
            cout << "Not Found" << endl;
        } else {
            vector<string> ids = Query[kase-1].at(qstr);
            sort(ids.begin(), ids.end());
            size = ids.size();
            for (int j = 0; j < size; j++) {
                cout << ids[j] << endl;
            }
        }

    }

    return 0;
}
