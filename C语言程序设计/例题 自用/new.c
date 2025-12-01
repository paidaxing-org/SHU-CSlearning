#include <stdio.h>
#include <string.h>
int main() {
    char a[20], zifu;
    int weizhi, i;
    printf("Enter a string:");
    fgets(a, sizeof(a), stdin);
    if (a[strlen(a) - 1] == '\n') {
        a[strlen(a) - 1] = '\0';
    }
    scanf("%d %c", &weizhi, &zifu);
    for (i = strlen(a); i >= weizhi; i--) {
        a[i + 1] = a[i];
    }
    a[weizhi] = zifu;
    puts(a);
    return 0;
}
