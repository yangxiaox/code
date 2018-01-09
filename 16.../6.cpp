/*************************************************************************
	> File Name: 6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月24日 星期五 17时30分32秒
 ************************************************************************/

#include<iostream>
#include <unordered_map>
#include <hash_map>
#include <string>
#include <functional>
using namespace std;

int main() {
    hash<int> mp;
    cout << mp(100) << endl;
    mp[100] = 1;
    //mp[200]+=2;
    int i = 0;
    /*for (auto x : mp) {
        cout << i << endl;
        cout << x.first << " " << x.second << endl;
    }*/
    return 0;
}
