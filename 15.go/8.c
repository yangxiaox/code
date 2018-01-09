/*************************************************************************
	> File Name: 8.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 00时43分13秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define MAX_N 40000

int prime[MAX_N + 5] = {0};
int isPrime[MAX_N + 5] = {0};
int d[MAX_N + 5] = {0};
int nums[MAX_N + 5] = {0};

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
            nums[i] = 2;
            prime[++prime[0]] = i;
            isPrime[i] = i;
            d[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; ++j) {
            if (i % prime[j] == 0) {
                nums[i * prime[j]] = nums[i] * (func(i, prime[j]) + 2) / (func(i, prime[j]) + 1);
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] * prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            }
            nums[i * prime[j]] = nums[i] * 2;
            isPrime[i * prime[j]] = prime[j];
            d[i * prime[j]] = d[i] * d[prime[j]];
        }
    }/*
    for (int i = 2; i < 500; ++i) {
        printf("%d->%d  |", i, nums[i]);
    }
    printf("\n\n");*/
    printf("%d-%d-------------------\n", nums[12376/2], nums[12376- 1]);
    printf("%d-%d-------------------\n", nums[721/2], nums[721 - 1]);
    long long many1, many2, ret;
    for (int i = 2; i <= MAX_N; i += 2) {
        many1 = nums[i / 2] * nums[i - 1];
        many2 = nums[i / 2] * nums[i + 1];
        if (many1 >= 500) {
            printf("%d----\n", i);
            ret = i / 2 * (i - 1);
            break;
        }
        if (many2 >= 500) {
            printf("%d++++\n", i);
            ret = i / 2 * (i + 1);
            break;
        }
    }
    printf("%lld\n", ret);
    return 0;
}
