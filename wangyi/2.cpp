/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月27日 星期二 21时08分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    int nums = r - l + 1;
    cout << nums - ((nums - ((l + 2) % 3)) / 3) << endl;
    return 0;
}
