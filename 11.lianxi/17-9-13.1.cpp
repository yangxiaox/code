/*************************************************************************
	> File Name: 17-9-13.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月13日 星期三 13时29分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

void my_sort(int *arr, int l, int r) {
    while (l < r) {
        int z = arr[(l + r) >> 1];
        int x = l, y = r;
        while (x <= y) {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                //arr[x] ^= arr[y];
                //arr[y] ^= arr[x];
                //arr[x] ^= arr[y];
                swap(arr[x], arr[y]);
                ++x;
                --y;
            }
        }
        my_sort(arr, l, y);
        l = x;
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", (arr + i));
    }
    my_sort(arr, 0, n - 1);
    printf("%d", arr[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return 0;
}
