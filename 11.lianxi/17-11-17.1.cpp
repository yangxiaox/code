/*************************************************************************
	> File Name: 17-11-17.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 11时51分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

int isPrime[10005] = {0};
int prime[10005] = {0};
int d[10005] = {0};

int main() {
    for (int i = 2; i < 10000; ++i) {
        if (!isPrime[i]) {
            isPrime[i] = i;
            d[i] = i + 1;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= 10000; ++j) {
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] *prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            }
            isPrime[i * prime[j]] = prime[j];
            d[i * prime[j]] = d[prime[j]] * d[i];
        }
    }
    for (int i = 0; i < 10000; ++i) {
        d[i] -= i;
    }
    int sum = 0;
    for (int i = 0; i < 10000; ++i) {
        if (d[i] <= 10000 && d[i] != i && d[d[i]] == i) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}

