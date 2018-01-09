/*************************************************************************
	> File Name: 17-11-17.9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 15时16分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <inttypes.h>
 
#define MAX_N 40000
 
int64_t prime[MAX_N + 5] = {0};
int64_t prime2[MAX_N + 5] = {0};
int64_t numFactor[MAX_N + 5] = {0};
 
int64_t HowMany(int64_t &x, int64_t p) {
    if (x == 1 || p == 1) return 0;
    int64_t ret = 0;
    while (x % p == 0) x /= p, ret++;
    return ret;
}
 
int64_t HowManyFactor(int64_t x, int64_t *p) {
    int64_t many = 1;
    while (x != 1) {
        many *= (HowMany(x, p[x]) + 1);
    }
    many *= (HowMany(x, x) + 1);
    return many;
}
 
void InitPrime(int64_t *p, int64_t range, int64_t *p2) {
    for (int i = 2; i <= range; i++) {
        if (!p[i]) {p2[++p2[0]] = i; p[i] = i;}
        for (int j = 1; j <= p2[0] && p2[j] * i <= range; j++) {
            p[p2[j] * i] = p2[j];
            if (i % p2[j] == 0) break;
        }
    }
}
 
int main() {
    InitPrime(prime, MAX_N, prime2);
    for (int i = 1; i <= MAX_N; i++) {
        numFactor[i] = HowManyFactor(i, prime);
    }
    int64_t many1, many2, ret;
    for (int64_t i = 2; i <= MAX_N; i += 2) {
        many1 = numFactor[i / 2] * numFactor[i - 1];
        many2 = numFactor[i / 2] * numFactor[i + 1];
        if (many1 >= 500) {
            ret = i / 2 * (i - 1);
            break;
        } else if (many2 >= 500) {
            ret = i / 2 * (i + 1);
            break;
        }   
    }
    std::cout << ret << std::endl;
    return 0;
}
