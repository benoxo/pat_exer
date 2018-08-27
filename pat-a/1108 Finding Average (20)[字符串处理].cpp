#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

bool IsLegal(char input[], double &Num) {
    int dot = 0;
    int decimal = 0;
    int len = strlen(input);
    char *pstr;

    if (len == 0) return false;
    if (!isdigit(input[0]) && input[0] != '-') return false;
    for (int i = 1; i < len; i++) {
        if (input[i] == '.') {
            dot++;
        } else if (isdigit(input[i]) && dot > 0) {
            decimal++;
        } else if (!isdigit(input[i])) {
            return false;
        }
    }
    if (dot > 1) return false;
    if (decimal > 2) return false;
    Num = strtod(input, &pstr);
    if (Num > 1000 || Num < -1000) return false;
    return true;
}

int main() {
    int N, K;
    double Sum, Num;
    char input[100];

    scanf("%d", &N);
    K = 0;
    Sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s", input);
        if (IsLegal(input, Num)) {
            Sum += Num;
            K++;
        } else {
            printf("ERROR: %s is not a legal number\n", input);
        }
    }

    if (K == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (K == 1) {
        printf("The average of 1 number is %.2lf", Sum);
    } else {
        printf("The average of %d numbers is %.2lf", K, Sum/K);
    }
    return 0;
}

