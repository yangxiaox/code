/*************************************************************************
	> File Name: 17-11-17.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 12时32分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_SUM 1000000

int isPrime[MAX_SUM + 5] = {0};
int prime[MAX_SUM + 5] = {0};
int d[MAX_SUM + 5] = {0};
int min_prime[MAX_SUM + 5] = {0};

int houmany(int &x, int p) {
    if (x == 1 || p == 1) return 0;
    int res = 0;
    while (x % p == 0) {
        x /= p;
        res++;
    }
    return res;
}

int houmanyhactor(int x, int *p) {
    int sum = 1;
    while (x != 1) {
        sum *= (houmany(x, p[x]) + 1);
    }
    return sum;
}

int main() {
    for (int i = 2; i < MAX_SUM; ++i) {
        if (!isPrime[i]) {
            isPrime[i] = i;
            prime[++prime[0]] = i;
            d[i] = i + 1;
            min_prime[i] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_SUM; ++j) {
            min_prime[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] * prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            }
            isPrime[i * prime[j]] = prime[j];
            d[i * prime[j]] = d[i] * d[prime[j]];
        }
    }
    int n;
    cin >> n;
    cout << d[n] << "  " << houmanyhactor(n, min_prime) << endl;
    /*
    for (int i = 0; i < MAX_SUM; ++i) {
        d[i] -= i;
    }
    int sum = 0;
    for (int i = 0; i < MAX_SUM; ++i) {
        if (d[i] < MAX_SUM && d[i] != i && d[d[i]] == i) {
            sum += i;
        }
    }*/
    return 0;
}
