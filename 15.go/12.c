/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月22日 星期三 17时01分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define INF 0x7fffffff

int n, m, min_cost = INF;
int weight[4100], lenght[13], road[13][13];

int min(int a, int b) {
    return a < b ? a : b;
}

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            road[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int house_a, house_b, dis;
        scanf("%d%d%d", &house_a, &house_b, &dis);
        road[house_a][house_b] = min(road[house_a][house_b], dis);
        road[house_b][house_a] = min(road[house_b][house_a], dis);
    }
    return ;
}

void find(int x) {
    for (int i = 1; i <= n; ++i) {
        if (x & (1 << (i - 1))) {
            for (int j = 1; j <= n; ++j) {
                if (!(x & (1 << (j - 1))) && road[i][j] != INF) {
                    if (weight[x | (1 << (j - 1))] > weight[x] + lenght[i] * road[i][j]) {
                        int temp = lenght[j];
                        lenght[j] = lenght[i] + 1;
                        weight[x | (1 << (j - 1))] = weight[x] + lenght[i] * road[i][j];
                        find(x | (1 << (j - 1)));
                        lenght[j] = temp;
                    }
                }
            }
        }
    }
    return ;
}

void solve() {
    for (int start = 1; start <= n; ++start) {
        for (int i = 1; i <= n; ++i) {
            lenght[i] = INF;
        }
        for (int i = 1; i < (1 << n); ++i) {
            weight[i] = INF;
        }
        lenght[start] = 1;
        weight[1 << (start - 1)] = 0;
        find(1 << (start - 1));
        min_cost = min(min_cost, weight[(1 << n) - 1]);
    }
    printf("%d\n", min_cost);
    return ;
}

int main() {
    init();
    solve();
    return 0;
}
