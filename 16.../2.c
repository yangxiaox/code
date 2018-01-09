/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 09时09分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int a[1050] = {0};
int b[1050] = {0};

int main() {
    a[0] = a[1] = 1;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= a[0]; ++j) {
            a[j] *= i;
        }
        for (int j = 1; j <= a[0]; ++j) {
            if (a[j] < 10) continue;
            a[j + 1] += (a[j] / 10);
            a[j] %= 10;
            if (j == a[0]) ++a[0];
        }
    }
    b[0] = b[1] = 1;
    for (int i = 1; i <= a[0]; ++i) {
        if (a[i] == 0) continue;
        for (int j = 1; j <= b[0]; ++j) {
            b[j] *= a[i];
        }
        for (int j = 1; j <= b[0]; ++j) {
            if (b[j] < 10) continue;
            b[j + 1] += (b[j] / 10);
            b[j] %= 10;
            if (j == b[0]) ++ b[0];
        }
    }
    for (int i = b[0]; i > 0; --i) {
        printf("%d", b[i]);
    }
    return 0;
}
