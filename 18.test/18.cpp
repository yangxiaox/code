/*************************************************************************
	> File Name: 18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月31日 星期日 17时13分44秒
 ************************************************************************/

#include <cstdio> 
#include <iostream>

using namespace std;

#define MAX_KEEP_RANGE 50000000
#define MAX_N 1000000
 
int32_t skeep[MAX_KEEP_RANGE + 5] = {0};
 
int32_t KeepChainLength(int64_t x) {
    if (x == 1) return 1;
    if (x <= MAX_KEEP_RANGE && skeep[x] != 0) return skeep[x];
    int32_t ans;
    switch (x % 2) {
        case 0 : 
            ans = KeepChainLength(x >> 1) + 1;
            break;
        case 1 :
            ans = KeepChainLength(3 * x + 1) + 1;
            break;
    }
    if (x <= MAX_KEEP_RANGE) skeep[x] = ans;
    cout << x << "  " << ans << endl;
    return ans;
}
 
int main() {
    int32_t maxi = 1;
    for (int32_t i = 2; i <= MAX_N; ++i)
        if (KeepChainLength(i) > KeepChainLength(maxi))
            maxi = i;
    printf("%d (chain length : %d)\n",maxi, KeepChainLength(maxi));
    return 0;
}
