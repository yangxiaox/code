/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月26日 星期日 15时45分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>



int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[k] > nums[j]) {
                k = j;
            }
        }
        if (k != i) {
            int temp = nums[k];
            nums[k] = nums[i];
            nums[i] = temp;
        }
    }
    
    
    
    
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
