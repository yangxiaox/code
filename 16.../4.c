/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 09时16分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};


int main() {
    int M = 9, N = 9973;
    int n = N - 1, m = 1, ind = 0;
    while (m <= n) {
        ++ind;
        m *= ind;
    }
    m /= ind;
    for (int i = M - ind; i < M && n; ++i) {
        --ind;
        int j = i + 1;
        while (m <= n && j < M) {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
            n -= m;
            ++j;
        }
        m /= ind;
    }
    for (int i = 0; i < 9; ++i) {
        printf("%d", a[i]);

    }
    return 0;
}
