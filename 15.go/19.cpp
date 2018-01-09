/*************************************************************************
	> File Name: 19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 23时24分05秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[10];
    for (int i = 1; i <= 10; ++i) {
        a[i - 1] = ((pow(2, i) - 1) * pow(2, i - 1));
    }
    int n;
    cin >> n;
    int i = 0;
    for (; i < 10; ++i) {
        if (n < a[i]) {
            break;
        }
    }
    i--;
    for (; i >= 0; --i) {
        if (n % a[i] == 0) break;
    }
    cout << a[i] << endl;
    return 0;
}
