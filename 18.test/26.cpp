/*************************************************************************
	> File Name: 26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月23日 星期二 11时32分42秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for (auto &x : a) {
        x = x * x;
    }
    for (auto x : a) {
        cout << x << endl;
    }
    
    
    return 0;
}
