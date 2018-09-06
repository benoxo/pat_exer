#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct Stu {
    string ID;
    int PScore, MScore, FScore;
    double Final;
    Stu() : PScore(-1), MScore(-1), FScore(-1) {};
} Student;
map<string, Student> stumap;
vector<Student> stus;

bool cmp(Student A, Student B) {
    if (A.Final != B.Final) return A.Final > B.Final;
    return A.ID < B.ID;
}

int main() {
    int P, M, N;

    scanf("%d %d %d", &P, &M, &N);
    for (int i = 0; i < P; i++) {
        Student S;
        cin >> S.ID >> S.PScore;
        stumap.insert(make_pair(S.ID, S));
    }

    for (int i = 0; i < M; i++) {
        Student S;
        cin >> S.ID >> S.MScore;
        if (stumap.find(S.ID) == stumap.end()) {
            stumap.insert(make_pair(S.ID, S));
        } else {
            stumap[S.ID].MScore = S.MScore;
        }
    }

    for (int i = 0; i < N; i++) {
        Student S;
        cin >> S.ID >> S.FScore;
        if (stumap.find(S.ID) == stumap.end()) {
            stumap.insert(make_pair(S.ID, S));
        } else {
            stumap[S.ID].FScore = S.FScore;
        }
    }

    map<string, Student>::iterator it = stumap.begin();
    while (it != stumap.end()) {
        if (it->second.MScore > it->second.FScore) {
            it->second.Final = round(it->second.MScore * 0.4 + it->second.FScore * 0.6);
        } else {
            it->second.Final = it->second.FScore;
        }
        stus.push_back(it->second);
        it++;
    }

    sort(stus.begin(), stus.end(), cmp);
    for (int i = 0; i < stus.size(); i++) {
        if (stus[i].PScore >= 200 && stus[i].Final >= 60) {
            cout << stus[i].ID << " " << stus[i].PScore << " " <<
                    stus[i].MScore << " " << stus[i].FScore << " " <<
                    stus[i].Final << endl;
        }
    }

    return 0;
}
