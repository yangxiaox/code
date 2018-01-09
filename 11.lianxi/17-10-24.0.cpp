/*************************************************************************
	> File Name: 17-10-24.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时23分02秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string operator* (const string &str, const int& k) {
    string result = "";
    int x = k;
    while (x--) {
        result = result + str;
    }
    return result;
}

int main() {
    string s = "aab";
    string x;
    x = s * 2;
    cout << x << endl;
    
    return 0;
}
