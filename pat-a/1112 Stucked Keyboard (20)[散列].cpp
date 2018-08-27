#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    vector<char> possible;
    int K, repeate, Hash[256];
    char input[1010], C;

    C = 0;
    repeate = 0;
    scanf("%d", &K);
    memset(Hash, -1, sizeof(Hash));
    scanf("%s", input);
    for (int i = 0; i <= strlen(input); i++) {
        if (C == 0) C = input[i];
        if (C == input[i]) {
            repeate++;
        } else {
            if (repeate % K) {
                Hash[C] = false;
            } else if (Hash[C] == -1) {
                Hash[C] = true;
                possible.push_back(C);
            }
            repeate = 1;
            C = input[i];
        }
    }

    for (int i = 0; i < possible.size(); i++) {
        if (Hash[ possible[i] ] == true) {
            printf("%c", possible[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < strlen(input); i++) {
        printf("%c", input[i]);
        if (Hash[ input[i] ]) {
            i += K-1;
        }
    }
    return 0;
}
