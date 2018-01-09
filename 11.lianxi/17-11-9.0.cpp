/*************************************************************************
	> File Name: 17-11-9.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月09日 星期四 10时42分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a>> b;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}
