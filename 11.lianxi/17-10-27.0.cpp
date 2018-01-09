/*************************************************************************
	> File Name: 17-10-27.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月27日 星期五 13时34分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define TEE(a, b)   cout << a << " " << #b << a##b << endl;

int main() {
    int a = 5;
    int adds = 2;
    TEE(a, dds);
    return 0;
}
