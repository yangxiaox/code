/*************************************************************************
	> File Name: 15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 18时10分53秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, pair<int, int>> mp;

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name;
        int value;
        cin >> name >> value;
        pair<int, int> p = {value, -1};
        mp[name] = p;
    }
    cin >> m;
    for (int s = 0; s < m; ++s) {
        int num;
        int sum = 0;
        int flag = 0;
        cin >> num;
        for (int i = 0; i < num; ++i) {
            string name;
            cin >> name;
            if (flag) continue;
            auto iter = mp.find(name);
            if (iter != mp.end()) {
                pair<int ,int> p = mp[name];
                if (mp[name].second != s) {
                    sum += mp[name].first;
                    mp[name].second = s;
                }
            } else {
                flag = 1;
            }
        }
        if (flag) {
            cout << "-1" << endl;
            continue;
        }
        cout << sum << endl;
    }
    return 0;
}
