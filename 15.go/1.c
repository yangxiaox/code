/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 17时58分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int isPrime[MAX_N + 5] = {0};
int d[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!isPrime[i]) {
            prime[++prime[0]] = i;
            isPrime[i] = i;
            d[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; ++j) {
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] * prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            }
            isPrime[i * prime[j]] = prime[j];
            d[i * prime[j]] = d[i] * d[prime[j]];
        }
    }
    int sum = 0, j;
    for (int i = 2; i <= MAX_N; ++i) {
        if (d[i] > sum) {
            sum = d[i];
            j = i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
