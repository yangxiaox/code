/*************************************************************************
	> File Name: 17-10-7.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月07日 星期六 19时42分50秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

template<typename T>
void print(T a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(T a, ARGS... args) {
    cout << a << " ";
    print(args...);
}


int main() {
    string a = "hello";
    print(a, "world", "hahaha", 1, 2, 3.4, 5.678);
    return 0;
}
