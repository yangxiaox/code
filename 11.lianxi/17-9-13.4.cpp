/*************************************************************************
	> File Name: 17-9-13.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月13日 星期三 22时00分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

//给定一个n 求一个结果
//规定你最多可以使用2个相同的pow(2,i),去组合
//有多少种组合方法
//例如n=4,  4  2+2  2+1+1  有3种

typedef pair<int, int> P;

int func(int n) {
    //int ans = 0;
    int pre_ind = 1;
    P pre, now;
    pre.first = 1, pre.second = 0;
    now.first = 0, now.second = 0;
    while (n) {
        if (n & 1) {
            now.first++;
        } else {
            if (pre_ind) {
                pre.first = (now.first * now.second + 1);
                pre.second = now.second;
                now.first = 0;
                now.second = 1;
            } else {
                now.second++;
            }
        }
        /*
        if (pre_ind && !(n & 1)) {
            //ans = (now.first * now.second + 1) * pre.first + now.first * pre.second;
            pre.first = (now.first * now.second + 1);
            pre.second = now.second;
            now.first = 0;
            now.second = 1;
        } else if (!pre_ind && !(n & 1)) {
            now.second++;
        } else {
            now.first++;
        }*/
       // if (n == 0) {
       //     n = -1;
       // }
        pre_ind = (n & 1);
        n >>= 1;
    }
    //return ans;
    return ((now.first * now.second + 1) * pre.first + now.first * pre.second);
}

int main() {
    int n;
    while (cin >> n) {
        cout << "__" << n << " = " <<func(n) << endl;
    }
    return 0;
}
