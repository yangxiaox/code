/*************************************************************************
	> File Name: 17-11-17.5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 13时23分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    while (scanf("%s%s", a, b) != EOF) {
        int sum[200] = {0};
        int l1 = strlen(a);
        int l2 = strlen(b);
        for (int i = l1 - 1; i >= 0; --i) {
            sum[0] = l2 + l1 - i - 1;
            int x = a[i] - '0';
            for (int j = l2 - 1; j >= 0; --j) {
                sum[l2 - j + l1 - i - 1] += x * (b[j] - '0');
            }
            for (int j = l1 - i; j <= sum[0]; ++j) {
                if (sum[j] < 10) continue;
                sum[j + 1] += sum[j] / 10;
                sum[j] %= 10;
                if (j == sum[0]) sum[0]++;
            }
        }
        for (int i = sum[0]; i >= 1; --i) {
            printf("%d", sum[i]);
        }
        printf("\n");
    }
}
