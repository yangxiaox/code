/*************************************************************************
	> File Name: 25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月21日 星期日 10时53分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

//16807 ?

int main() {
    int flag = 0;
    for (int i = 2; i < 16807; i++) {
        if (flag) break;
        if (16807 % i == 0) {
            cout << "16807 -> " << i << endl;
            flag = 1;
        }
    }
    cout << flag << endl;


    return 0;
}
