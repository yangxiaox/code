/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 14时32分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    pair<int, string> p1;
    pair<int, string> p2;
    cout << "p1.second = " << p1.second <<endl;
    cout << &p1.second << endl;
    cout << "p2.second = " << p2.second <<endl;
    cout << &p2.second << endl;
    p1.second = p2.second;
    
    string s1 = "asd";
    string s2 = "asd";
    cout << (s1 == s2) << endl;
    s2 = s1;
    return 0;
}
