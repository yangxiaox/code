/*************************************************************************
	> File Name: 17-9-15.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月15日 星期五 17时08分28秒
 ************************************************************************/

//给定N个无序的数，找出第K个大的数x。

#include<iostream>
using namespace std;

int searchk(int *data, int length, int k, int max, int min) {
    int max_k = 0, th = 0, index = (max + min) / 2;
    for (int i = 0; i < length; ++i) {
        if (data[i] > index) max_k++;
        if (data[i] == index) th++;
    }
    if (k > max_k && k <= (max_k + th)) return index;
    if (k <= max_k) return searchk(data, length, k, max, index + 1);
    else return searchk(data, length, k, index, min);
}

int main() {
    int n, k;
    cin >> n;
    int *data = (int *)malloc(sizeof(int) * n);
    cin >> data[0];
    int max = data[0], min = data[0];
    for (int i = 1; i < n; ++i) {
        cin >> data[i];
        if (data[i] > max) max = data[i];
        if (data[i] < min) min = data[i];
    }
    cin >> k;
    int x = searchk(data, n, k, max, min);
    cout << x << endl;
    return 0;
}
