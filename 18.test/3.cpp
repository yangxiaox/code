/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 11时16分03秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int a, b, num;
    char c;
    cin >> a >> c >> b;
    switch (c) {
        case '+' :
            num = a + b;
            break;
        case '-' :
            num = a - b;
            break;
        case '*' :
            num = a * b;
            break;
        case '/' :
            num = a / b;
            break;
        case '%' :
            num = a % b;
            break;
        default:
            cout << "scan error !" << endl;
            return 1;
    }
    cout << num << endl;
    return 0;
}
