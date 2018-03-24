#include <iostream>
#include <algorithm>

using namespace std;

int p[100250] = {0};
int q[100250];

int main() {
    int N, K, H, x;
    cin >> N >> K >> H;
    for(int i = 1; i <= N; ++i) {
        cin >> x;
        p[x]++;
    }
    q[0] = 0;
    for (int i = 1; i < 100250; ++i) {
        q[i] = -1;
    }
    int nums = 0;

    for(int i = 0 ; i <= 100000 + 100; ++i) {
        if(q[i] != -1 && q[i] < K) {
            for(int j = i + 1; j <= i + H; ++j) {
                int tmp = j + (j - i);
                if(p[j] > 0) {
                    if(q[tmp] == -1 || q[tmp] > q[i] + 1) {
                        q[tmp] = q[i] + 1;
                    }
                    nums = max(nums, tmp);
                }
            }
        }
    }
    cout << nums;
    return 0;
}
