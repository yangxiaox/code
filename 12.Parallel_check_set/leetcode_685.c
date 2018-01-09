/*************************************************************************
	> File Name: leetcode_685.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月05日 星期日 15时12分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct UnionSet {
	int *father;
	int *size;
} UnionSet;

UnionSet *init(int n) {
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet) * 1);
	u->father = (int *)malloc(sizeof(int) * n);
	u->size = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		u->father[i] = i;
		u->size[i] = 1;
	}
	return u;
}

int find(UnionSet *u, int ind) {
	if (u->father[ind] == ind) {
		return u->father[ind];
	}
	int father = find(u, u->father[ind]);
	u->father[ind] = father;
	return father;
}

int Union(UnionSet *u, int p, int q) {
	int i = find(u, p);
	int j = find(u, q);
	if (i == j) return 0;
	if (u->size[i] > u->size[j]) {
		u->father[j] = i;
		u->size[j] += u->size[i];
	} else {
		u->father[i] = j;
		u->size[i] += u->size[j];
	}
	return 1;
}

void clear(UnionSet *u) {
	free(u->father);
	free(u->size);
	free(u);
}

int check_connect(int **edges, int n, int s, int t) {
    UnionSet *u = init(n);
    for (int i = 0; i < n; i++) {
    	if (edges[i][0] == s && edges[i][1] == t) continue;
    	Union(u, edges[i][0] - 1, edges[i][1] - 1);
    }
    int ret = (find(u, s - 1) == find(u, t - 1));
    clear(u);
    return ret;
}

int* findRedundantDirectedConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize) {
	int n = edgesRowSize;
    UnionSet *u = init(n);
    int *ret = (int *)malloc(sizeof(int) * 2);
    int *ind = (int *)calloc(n, sizeof(int));
    int *outd = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
    	ind[edges[i][1] - 1]++;
    	outd[edges[i][0] - 1]++;
    }
    for (int i = n - 1; i >= 0; i--) {
    	if (ind[edges[i][1] - 1] <= 1 || !check_connect(edges, n, edges[i][0], edges[i][1])) continue;
    	*returnSize = 2;
    	ret[0] = edges[i][0];
    	ret[1] = edges[i][1];
    	free(ind); free(outd);
    	return ret;
    }

   	// 整理树的拓扑结构
    int *father = (int *)malloc(n * sizeof(int));
	int *queue = (int *)malloc(n * sizeof(int));
	int head = 0, tail = 0;
	for (int i = 0; i < n; i++) {
		father[edges[i][1] - 1] = edges[i][0] - 1;
		if (outd[i] == 0) {
			queue[tail++] = i;
		}
	}
	while (head < tail) {
		int ind = queue[head++];
		outd[father[ind]]--;
		if (outd[father[ind]] == 0) {
			queue[tail++] = father[ind];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (outd[edges[i][0] - 1] == 0 || outd[edges[i][1] - 1] == 0) continue;
		*returnSize = 2;
    	ret[0] = edges[i][0];
    	ret[1] = edges[i][1];
    	break;
	}
	free(ind);
	free(outd);
	free(father);
	free(queue);
    return ret;
}
