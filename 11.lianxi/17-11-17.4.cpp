/*************************************************************************
	> File Name: 17-11-17.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 12时59分11秒
 ************************************************************************/

//a^b

#include <stdio.h>
#include <string.h>

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int ans[10000] = {0};
		ans[0] = ans[1] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= ans[0]; j++) {
				ans[j] *= n;
			}
			for (int j = 1; j <= ans[0]; j++) {
				if (ans[j] < 10) continue;
				ans[j + 1] += ans[j] / 10;
				ans[j] %= 10;
				if (j == ans[0]) ans[0]++;
			}
		}
		for (int i = ans[0]; i >= 1; i--) {
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
