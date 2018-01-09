/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 17时58分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int isPrime[MAX_N + 5] = {0};
int d[MAX_N + 5] = {0};
int sum[MAX_N + 5] = {0};

int func(int a, int b) {
    int i = 0;
    while (a % b == 0) {
        a /= b;
        i++;
    }
    return i;
}

int main() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!isPrime[i]) {
            prime[++prime[0]] = i;
            isPrime[i] = i;
            sum[i] = 2;
            d[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; ++j) {
            if (i % prime[j] == 0) {
                sum[i * prime[j]] = sum[i] * (func(i, prime[j]) + 2) / (func(i, prime[j]) + 1);
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] * prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            }
            sum[i * prime[j]] = sum[i] * 2;
            isPrime[i * prime[j]] = prime[j];
            d[i * prime[j]] = d[i] * d[prime[j]];
        }
    }
    int num = 0;
    for (int i = 2; i <= MAX_N; ++i) {
        if (d[i] * sum[i] > num) {
            num = d[i] * sum[i];
        }
    }
    printf("%d\n", num);
    return 0;
}
