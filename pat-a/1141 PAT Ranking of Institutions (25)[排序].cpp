#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef struct {
    string ID, School;
    int Score;
} Testee;

typedef struct Sch {
    string ID;
    int Rank, TWS, Ns, AS, BS, TS;
    Sch():Ns(0), AS(0), BS(0), TS(0), TWS(0){};
    bool operator <(const Sch B) const {
        if (TWS != B.TWS) return TWS > B.TWS;
        if (Ns != B.Ns) return Ns < B.Ns;
        return ID < B.ID;
    }
} School;

vector<School> schools;
map<string, int> schmap;

string LowerCase(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < 'a') {
            str[i] += 32;
        }
    }
    return str;
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        Testee t;
        cin >> t.ID >> t.Score >> t.School;
        t.School = LowerCase(t.School);
        if (schmap.find(t.School) == schmap.end()) {
            schmap[t.School] = schools.size();
            School s;
            s.ID = t.School;
            s.Ns = 1;
            switch(t.ID[0]) {
            case 'B': s.BS += t.Score; break;
            case 'A': s.AS += t.Score; break;
            case 'T': s.TS += t.Score; break;
            }
            schools.push_back(s);
        } else {
            int index = schmap[t.School];
            switch(t.ID[0]) {
            case 'B': schools[index].BS += t.Score; break;
            case 'A': schools[index].AS += t.Score; break;
            case 'T': schools[index].TS += t.Score; break;
            }
            schools[index].Ns++;
        }
    }

    for (int i = 0; i < schools.size(); i++) {
        schools[i].TWS = (int)(schools[i].BS/1.5 + schools[i].AS + schools[i].TS*1.5);
    }
    sort(schools.begin(), schools.end());

    schools[0].Rank = 1;
    cout << schools.size() << endl;
    cout << schools[0].Rank << " " << schools[0].ID << " "
        << schools[0].TWS << " " << schools[0].Ns << endl;
    for (int i = 1; i < schools.size(); i++) {
        if (schools[i].TWS == schools[i-1].TWS) {
            schools[i].Rank = schools[i-1].Rank;
        } else {
            schools[i].Rank = i+1;
        }
        cout << schools[i].Rank << " " << schools[i].ID << " "
        << schools[i].TWS << " " << schools[i].Ns << endl;
    }

    return 0;
}
