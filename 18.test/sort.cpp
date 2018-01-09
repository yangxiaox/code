/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月26日 星期日 13时24分45秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int nums[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = i + 1; j > 0; --j) {
            if (nums[j] < nums[j - 1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
