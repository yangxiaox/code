/*************************************************************************
	> File Name: 17-10-22.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月22日 星期日 11时14分08秒
 ************************************************************************/

#include<iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {
    int x = 123;
    string ss;
    while (x) {
        ss += (char)(x/(int)pow(10, log(x)) + '0');
        int y = (int)pow(10, (int)log(x) - 2);
        x = x % (int)pow(10, (int)log(x) - 2);
        cout << y << endl;
    }
    ss += '\0';
    cout << ss << endl;
    return 0;
}
