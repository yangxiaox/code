/*************************************************************************
	> File Name: 13.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月22日 星期三 18时00分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define INF 0x7fffffff

int n, m, ans = INF;
int weight[4100], lenght[13], rota[13][13];

int min(int a, int b) {
    return a < b ? a : b;
}

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            rota[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        rota[a][b] = min(rota[a][b], c);
        rota[b][a] = min(rota[b][a], c);
    }
    return ;
}


void find(int x) {
    for (int i = 1; i <= n; ++i) {
        if (x & 1 << (i - 1)) {
            for (int j = 1; j <= n; ++j) {
                if (!(x & 1 << (j - 1)) && rota[i][j] != INF) {
                    if (weight[x | 1 << (j - 1)] > weight[x] + lenght[i] * rota[i][j]) {
                        int temp = lenght[j];
                        lenght[j] = lenght[i] + 1;
                        weight[x | 1 << (j - 1)] = weight[x] + lenght[i] * rota[i][j];
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
    for (int s = 1; s <= n; ++s) {
        for (int i = 1; i <= n; ++i) {
            lenght[i] = INF;
        }
        for (int i = 1; i < (1 << n); ++i) {
            weight[i] = INF;
        }
        lenght[s] = 1;
        weight[1 << (s - 1)] = 0;
        find(1 << (s - 1));
        ans = min(ans, weight[(1 << n) - 1]);
    }
    printf("%d\n", ans);
    return ;
}

int main() {
    init();
    solve();
    return 0;
}
