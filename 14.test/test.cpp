/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月03日 星期日 08时29分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int i = 3;
    for (int i = 1; i < 5; ++i) {
        cout << i << endl;
    }
    do {
        break;
        cout << "x" << endl;
    } while(0);
    printf("%d\n", i);
    return 0;
}
