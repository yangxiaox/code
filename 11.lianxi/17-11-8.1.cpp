/*************************************************************************
	> File Name: 17-11-8.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月08日 星期三 18时05分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int xxx(int n) {
    int result[2] = {0, 1};
    if (n <= 2) {
        return result[n - 1];
    }
    int a1 = 0;
    int a2 = 1;
    int a3 = 0;
    for (int i = 2; i < n; ++i) {
        a3 = a1 + a2;

        a1 = a2;
        a2 = a3;
    }
    return a3;
}

int main () {
    int n = 5;
    cout << xxx(n) << endl;
    return 0;
}
