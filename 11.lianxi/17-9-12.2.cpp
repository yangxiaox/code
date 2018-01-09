/*************************************************************************
	> File Name: 17-9-12.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月12日 星期二 20时17分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

void my_sort2(int *arr, int l, int r) {
    if (l >= r) return ;
    int k = l;
    for (int i = l + 1; i < r; ++i) {
        if (arr[i] < arr[k]) k = i;
    }
    if (k != l) {
        arr[k] ^= arr[l];
        arr[l] ^= arr[k];
        arr[k] ^= arr[l];
    }
    for (int i = l + 1; i < r; ++i) {
        int j = i + 1;
        while (arr[j] < arr[j - 1]) {
            arr[j] ^= arr[j - 1];
            arr[j - 1] ^= arr[j];
            arr[j] ^= arr[j - 1];
            --j;
        }
    }
    return ;
}

void my_sort(int *arr, int l, int r) {
    if (r - l <= 32) {
        return my_sort2(arr, l, r);
    }
    while (r - l <= 32) {
        arr[l] ^= arr[(l + r) / 2];
        arr[(l + r) / 2] ^= arr[l];
        arr[l] ^= arr[(l + r) / 2];
        int z = arr[l];
        int x = l, y = r;
        while (x < y) {
            while (x < y && arr[y] >= z) --y;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= z) ++x;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        my_sort(arr, l, x - 1);
        l = x + 1;
    }
    my_sort2(arr, l, r);
    return ;
}

int main() {
    int n;
    cin >> n;
    int *arr = (int *)malloc(sizeof(int) * n + 1);
    for (int i = n - 1; i >= 0; --i) {
        cin >> arr[i];
    }
    my_sort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i) cout << " " << arr[i];
        else cout << arr[i];
    }
    cout << endl;
    return 0;
}
