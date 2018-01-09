/*************************************************************************
	> File Name: 17-10-7.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月07日 星期六 20时26分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T, typename U>
void add(T a, U b) {
    cout << a + b << endl;
}

template<typename T>
void add(double a, T b) {
    cout << "double and T :" << a + b << endl;
}
template<typename T>
void add(T a, double b) {
    cout << "T and double :" << a + b << endl;
}
template<>
void add(int a, int b) {
    cout << "int and int :" << a + b << endl;
}
template<typename T>
void add(T a, int b) {
    cout << "T and int :" << a + b << endl;
}
int main() {
    add((int)2, (int)3);
    //add(1.2, 2.3);
    //add(1.2, 2);
    add(1, 2.3);
    return 0;
}/*
template<>
void add(int a, int b) {*/
