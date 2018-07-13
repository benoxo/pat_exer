#include "stdio.h"
#include "string.h"
#define NOW 2014*365+9*30+6
typedef struct {
    int Birth = 0;
    char Name[10];
}Person;

int main() {
    int year, month, day, birth, N, counter;
    char name[10];
    Person oldest, youngest;
    
    scanf("%d", &N);
    counter = 0;
    oldest.Birth = NOW+1;
    youngest.Birth = NOW-200*365-1;
    while (N--) {
        scanf("%s %d/%d/%d", name, &year, &month, &day);
        birth = year*365+month*30+day;
        if (birth > NOW || NOW-birth > 200*365) continue;
        if (birth < oldest.Birth) {
            oldest.Birth = birth;
            strcpy(oldest.Name, name);
        }
        if (birth > youngest.Birth) {
            youngest.Birth = birth;
            strcpy(youngest.Name, name);
        }
        counter++;
    }
    
    if (counter == 0) {
        printf("0");
    } else {
        printf("%d %s %s", counter, oldest.Name, youngest.Name);
    }
    return 0;
} 
