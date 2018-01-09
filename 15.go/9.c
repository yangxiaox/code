/*************************************************************************
	> File Name: 9.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 11时06分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_N 40000

int prime[MAX_N + 5] = {0};
int isPrime[MAX_N + 5] = {0};
int pp[MAX_N + 5] = {0};

int func(int a, int b) {
    int sum = 0;
    while (a % b == 0) {
        a /= b;
        sum++;
    }
    return sum;
}

int main() {
    for (int i = 2; i < MAX_N; ++i) {
        if (!isPrime[i]) {
            pp[i] = 2;
            isPrime[i] = i;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; ++j) {
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                pp[i * prime[j]] = pp[i] * (func(i, prime[j]) + 2) / (func(i, prime[j]) + 1);
                break;
            }
            isPrime[i * prime[j]] = prime[j];
            pp[i * prime[j]] = pp[i] * 2;
        }
    }
    pp[1] = 1;
    for (int i = 2; i < MAX_N; i += 2) {
        int x1 = pp[i / 2] * pp[i + 1];
        int x2 = pp[i / 2] * pp[i - 1];
        if (x1 >= 500) {
            printf("%d\n", i / 2 * (i + 1));
            break;
        }
        if (x2 >= 500) {
            printf("%d\n", i / 2 * (i - 1));
            break;
        }
    }
    return 0;
}
