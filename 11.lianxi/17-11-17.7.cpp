/*************************************************************************
	> File Name: 17-11-17.7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 14时32分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define N 1000000
#define M 10

int a[M] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    int n = N - 1, m = 1, ind = 0;
    while (m <= n && ind < M) {
        ++ind;
        m *= ind;
    }
    m /= ind;
    for (int i = M - ind; i < M && n; ++i) {
        --ind;
        int j = i + 1;
        while (n >= m && j < M) {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
            n -= m;
            ++j;
        }
        m /= ind;
    }
    for (int i = 0; i < M; ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
