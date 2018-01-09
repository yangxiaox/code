/*************************************************************************
	> File Name: 18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 23时11分48秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 1, b = 2, c = 3;
    int flag = 1;
    for (int i = 0; i < n; ++i) {
        int win;
        cin >> win;
        if (win == a) {
            swap(b, c);
        } else if (win == b) {
            swap(a, c);
        } else {
            flag = 0;
        }
    }
    printf(flag ? "YES\n" : "NO\n");
    return 0;
}
