/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月27日 星期二 20时55分02秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string str;
        cin >> n;
        cin >> str;
        int flag[n + 3] = {0};
        flag[0] = flag[n + 2] = flag[n + 1] = 1;
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'X') {
                flag[i + 1] = 1;
            }
        }
        int nums = 0;
        for (int i = 1; i <= n; ++i) {
            if (flag[i] == 0) {
                nums++;
                flag[i] = flag[i + 1] = flag[i + 2] = 1;
            }
        }
        cout << nums << endl;
    }
    return 0;
}
