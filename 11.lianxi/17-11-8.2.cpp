/*************************************************************************
	> File Name: 17-11-8.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月08日 星期三 18时43分16秒
 ************************************************************************/

//有BUG

#include<iostream>
using namespace std;


int func(int a) {
    int b[3] = {7, 3, 1};
    if (a <= 3 && a > 0) return b[3 - a];
    int base[3][3] = { {0, 1, 0},
                       {2, 0, 1},
                       {3, 0, 0} };
    a -= 3;
    while (a != 0) {
        int b0 = b[0], b1 = b[1], b2 = b[2];
        if (a & 1) {
            b[0] = b0 * base[0][0] + b1 * base[1][0] + b2 * base[2][0];
            b[0] %= 9973;
            b[1] = b0 * base[0][1] + b1 * base[1][1] + b2 * base[2][1];
            b[1] %= 9973;
            b[2] = b0 * base[0][2] + b1 * base[0][2] + b2 * base[2][2];
            b[2] %= 9973;
        }
        int e1 = base[0][0], e2 = base[0][1], e3 = base[0][2];
        int e4 = base[1][0], e5 = base[1][1], e6 = base[1][2];
        int e7 = base[2][0], e8 = base[2][1], e9 = base[2][2];
        base[0][0] = e1 * e1 + e2 * e4 + e3 * e6;
        base[0][0] %= 9973;
        base[0][1] = e1 * e2 + e2 * e5 + e3 * e8;
        base[0][1] %= 9973;
        base[0][2] = e1 * e3 + e2 * e6 + e3 * e9;
        base[0][2] %= 9973;
        base[1][0] = e4 * e1 + e5 * e4 + e6 * e7;
        base[1][0] %= 9973;
        base[1][1] = e4 * e2 + e5 * e5 + e6 * e8;
        base[1][1] %= 9973;
        base[1][2] = e4 * e3 + e5 * e6 + e6 * e9;
        base[1][2] %= 9973;
        base[2][0] = e7 * e1 + e8 * e4 + e9 * e7;
        base[2][0] %= 9973;
        base[2][1] = e7 * e2 + e8 * e5 + e9 * e8;
        base[2][1] %= 9973;
        base[2][2] = e7 * e3 + e8 * e6 + e9 * e9;
        base[2][2] %= 9973;
        a >>= 1;
    }
    return b[0];
}


int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}
