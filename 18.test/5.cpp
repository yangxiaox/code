/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月16日 星期六 17时38分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int num = 7;
    string str = "555abc123";
    sscanf(str.c_str(), "%d", &num);
    cout << num << endl;
    return 0;
}

