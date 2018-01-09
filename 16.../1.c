/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 09时02分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_N 1000000

int priem[MAX_N + 5] = {0};
int isPriem[MAX_N + 5] = {0};
int d[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i < MAX_N; ++i) {
        if (!isPriem[i]) {
            isPriem[i] = i;
            priem[++priem[0]] = i;
            d[i] = i + 1;
        }
        for (int j = 1; j <= priem[0] && i * priem[j] < MAX_N; ++j) {
            if (i % priem[j] == 0) {
                isPriem[i * priem[j]] = isPriem[i] * priem[j];
                d[i * priem[j]] = d[i] * (isPriem[i] * priem[j] * priem[j] - 1) / (isPriem[i] * priem[j] - 1);
                break;
            }
            isPriem[i * priem[j]] = priem[j];
            d[i * priem[j]] = d[i] *d[priem[j]];
        }
    }
    int sum = 0;
    for (int i = 2; i < MAX_N; ++i) {
        if (d[i] > sum) {
            sum = d[i];
        }
    }
    printf("%d", sum);
    return 0;
}
