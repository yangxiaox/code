/*************************************************************************
	> File Name: 17-9-14.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月14日 星期四 19时25分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

int rand() {
    static int plus = 1;
    do {
        plus *= 10007;
        plus %= 10009;
    } while (plus > 10000);
    return plus;
}

#define MAX_N 20000

int pre[MAX_N] = {0};

int main() {/*
    for (int i = 2; i < 11000; ++i) {
        if (!pre[i]) {
            pre[++pre[0]] = i;
        }
        for (int j = 1; j <= pre[0]; ++j) {
            if (i * pre[j] > MAX_N) break;
            pre[i * pre[j]] = 1;
            if (i % pre[j] == 0) break;
        }
    }
    for (int i = 1; i < pre[0]; ++i) {
        cout << pre[i] << " ";
    }*/
    int arr[10001] = {0};
    for (int i = 0; i < 10000; ++i) {
        int x = rand();
        arr[x]++;
        if (arr[x] > 1) {
            cout << "error" << endl;
        }
    }
    cout << endl;
    return 0;
}
