/*************************************************************************
	> File Name: 17-9-12.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月12日 星期二 19时37分57秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int find_min(int *num, int n) {
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (num[i] < ans) ans = num[i];
    }
    return ans;
}

int main() {


    return 0;
}
