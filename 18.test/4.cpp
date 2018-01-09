/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月16日 星期六 15时37分56秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "a112b3cd";
    int num = 1;
    sscanf(str.c_str(), "%d", &num);
    cout << num << endl;

    return 0;
}
