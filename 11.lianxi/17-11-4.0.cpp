/*************************************************************************
	> File Name: 17-11-4.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月04日 星期六 10时01分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct color{
    
};

int main() {
    int n;
    cin >> n;
    int *data = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        data[i] = i;
    }
    int m;
    cin >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        int x = data[a];
        int y = data[b];
        for (int j = 0; j < n; ++j) {
            if (data[j] == y) {
                data [j] == b;
            }
        }
        if (x == y) {
            cout << "no" << endl;
        } else {
            cout << "ok" << endl;
        }
    }
    
    
    return 0;
}
