/*************************************************************************
	> File Name: 17-11-17.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 12时48分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_SUM 10000

int isPrime[MAX_SUM + 5] = {0};
int prime[MAX_SUM + 5] = {0};
int d[MAX_SUM + 5] = {0};

int main() {
    for (int i = 2; i < MAX_SUM; ++i) {
        if (!isPrime[i]) {
            isPrime[i] = i;
            prime[++prime[0]] = i;
            d[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_SUM; ++j) {
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] * prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            }
            isPrime[i * prime[j]] = prime[j];
            d[i * prime[j]] = d[i] * d[prime[j]];
        }
    }
    for (int i = 0; i < MAX_SUM; ++i) {
        d[i] -= i;
    }
    int sum = 0;
    for (int i = 0; i < MAX_SUM; ++i) {
        if (d[i] <= MAX_SUM && d[i] != i && d[d[i]] == i) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
