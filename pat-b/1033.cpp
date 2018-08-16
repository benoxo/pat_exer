#include <cstdio>
#include <cstring>

int main() {
    int broken[200];
    char c;
    
    memset(broken, 0, sizeof(broken));
    while (scanf("%c", &c) != EOF && c != '\n') {
        broken[c] = 1;
        if (c <= 'z' && c >= 'a') broken[c - 32] = 1;
        if (c <= 'Z' && c >= 'A') broken[c + 32] = 1;
    }
    
    while (scanf("%c", &c) != EOF) {
        if (broken[c] == 1 || (c >= 'A' && c <= 'Z' && broken['+'] == 1)) continue;
        printf("%c", c);
    }
    
    return 0;
}
