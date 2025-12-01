#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    int i, j = 0, n, sum = 0, number,factor;
    printf("Enter a string: ");
    fgets(a, sizeof(a), stdin);  // 使用 fgets() 代替 gets()
    n = strlen(a) - 1;  // 减1是因为 fgets() 会将换行符也读入
    for (i = 0; i < n; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            number = a[i] - '0';
        } else if (a[i] >= 'a' && a[i] <= 'f' || a[i] >= 'A' && a[i] <= 'F') {
            number = a[i] - 'a' + 10;
        } else {
            continue;  // 如果不是数字也不是十六进制字符，就跳过
        }
        b[j] = number;  // 将数字存入 b 数组
        j++;
    }
    b[j] = '\0';  // 在 b 数组的末尾添加空字符
    printf("New string: ");
    puts(b);
    factor = 1;  // 重置 factor 的值
    for (i = 0; i < j; i++) {
        sum += factor * b[i];  // 注意这里不需要使用 number 变量了，因为 b[i] 已经包含了数字的值
        factor *= 16;  // 更新 factor 的值
    }
    printf("number=%d\n", sum);  // 注意添加换行符 \n
    return 0;
}
