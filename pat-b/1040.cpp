#include <cstdio>
#include <cstring>

int main() {
    char str[100010];
    int len, i;
    long long int p, pa, pat;
    scanf("%s", str);
    len = strlen(str);

    p = pa = pat = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == 'P') {
            p++;
        } else if (str[i] == 'A') {
            pa += p;
        } else {
            pat +=pa;
        }
    }

    printf("%d", pat % 1000000007);
    return 0;
}
