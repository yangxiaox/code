/*************************************************************************
	> File Name: 17-9-13.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月13日 星期三 20时40分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int m = n;
        int sum = 1;
        int i = 0;
        int i1 = 1;
        while (n) {
            int x = (n & 1);
            i++;
            if (x) {
                sum = sum * (i - i1) + 1;
                if (i == i1) {
                    i1 = i + 1;
                } else {
                    i1 = i;
                }
            }
            n >>= 1;
        }
        cout << m << " = " << sum << endl;
    }
    
    return 0;
}
