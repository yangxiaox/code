/*************************************************************************
	> File Name: 17-9-13.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月13日 星期三 18时05分54秒
 ************************************************************************/

//给定一个n 求一个结果
//规定你最多可以使用2个相同的pow(2,i),去组合
//有多少种组合方法
//例如n=4,  4  2+2  2+1+1  有3种
//错误的做法

#include<iostream>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        int sum = 0;
        int num0 = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                if (num0) {
                    sum = sum * num0 + 1;
                }
            }
            else {
                num0++;
            }
        }
        cout << "sum = "<< sum << endl;
    }
    return 0;
}
