/*************************************************************************
	> File Name: 17-11-17.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 10时22分18秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

int main() {
    int *prime = (int *)calloc(150005, sizeof(int));
    for (int i = 2; i < 150000; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (i * prime[j] > 150000) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    cout << prime[0] << endl;
    cout << prime[prime[0]] << endl;
    long long a = pow(9, 13);
    cout << a << endl;
    return 0;
}
