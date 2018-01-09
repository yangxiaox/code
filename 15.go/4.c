/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 17时58分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    int N = 9973, M = 9;
    int n = 9972, m = 1, ind = 0;
    while (m <= n) {
        ++ind;
        m *= ind;
    }
    m /= ind;
    for (int i = M - ind; i < M && n; ++i) {
        ind--;
        int j = i + 1;
        while (m <= n && j < M) {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
            n -= m;
            j++;
        }
        m /= ind;
    }
    for (int i = 0; i < M; ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
