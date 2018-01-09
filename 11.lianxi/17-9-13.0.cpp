/*************************************************************************
	> File Name: 17-9-13.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月13日 星期三 13时22分50秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}
