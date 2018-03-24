#include <iostream>
using namespace std;

char num[100000200] = {0};

int main() {
    int n, k;
    cin >> n >> k;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        num[x] = 1;
    }
    int sum = 0;
    for (int i = 0; i <= 100000000; ++i) {
        if (num[i] == 1) {
            if (num[i + k] == 1) {
                ++sum;
            }
        }
    }
    
    cout << sum;
    
    return 0;
}
