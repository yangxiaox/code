/*************************************************************************
	> File Name: 17-10-17.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月17日 星期二 17时42分02秒
 ************************************************************************/

#include<iostream>
using namespace std;

void func(int &&a) {
    a = 4;
    a++;
    cout << a << endl;
    return;
}

void func(int &a) {
    a = 10;
    a++;
    cout << a << endl;
    return ;
}

int main() {
    int x = 1;
    func(forward<int>(x));
    int y = 2;
    func(move(y));
    x++;
    y++;
    cout << x << " " << y << endl;
    func(20);
    return 0;
}
