/*************************************************************************
	> File Name: 17-11-17.6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 14时16分53秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
 
#define N_STATUS 1000000
#define MAX_M 10
int32_t a[MAX_M] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 
int32_t main() {
    int32_t n = N_STATUS - 1, max_status = 1, ind = 0;
    while (max_status <= n && ind < MAX_M) {
        ++ind;
        max_status = max_status * ind;
    }
    max_status /= ind;
    for (int32_t i = MAX_M - ind; i < MAX_M && n; i++) {
        --ind;
        int32_t j = i + 1, k;
        while (n >= max_status && j < MAX_M) {
            k = a[i]; a[i] = a[j]; a[j] = k;
            n -= max_status; ++j;
        } 
        max_status /= ind;
    }
    for (int32_t i = 0; i < MAX_M; i++) {
        printf("%d", a[i]);
    }
    printf("\n"); 
    return 0;
}
