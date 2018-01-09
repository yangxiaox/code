/*************************************************************************
	> File Name: 6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月19日 星期二 19时09分00秒
 ************************************************************************/

#include <iostream>
#include <time.h>
using namespace std;

#define MAX_M 1000000
#define MAX_N 1000000

int f_ans[MAX_M + 5] = {0};

long long f(long long x) {
//int f(int x) {
    if (x == 1) return 1;
    if (x < MAX_M && f_ans[x] != 0) return f_ans[x];
    int ans;
    if (x & 1) ans = f(x * 3 + 1) + 1;
    else ans = f(x / 2) + 1;
    if (x < MAX_M) f_ans[x] = ans;
    return ans;
}

int main() {
    int begin = clock();
    int ans = -1, length = 0;
    for (int i = 1; i <= MAX_N; ++i) {
        int temp = f(i);
        if (temp > length) {
            length = temp;
            ans = i;
        }
    }
    int end = clock();
    printf("%d -> %d RUN : %lf secs\n", ans, length, 1.0 * (end - begin) / 1000000);
    return 0;
}
