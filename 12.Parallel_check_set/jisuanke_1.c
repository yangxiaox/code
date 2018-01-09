/*************************************************************************
	> File Name: jisuanke_1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月05日 星期日 08时34分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet {
    int *father;
    int *size;
    int n;
    int cnt;
} UnionSet;

UnionSet *intt(int n) {
    UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet));
    p->n = n;
    p->father = (int *)malloc(sizeof(int) * n);
    p->size = (int *)malloc(sizeof(int) * n);
    for (int i= 0; i < n; ++i) {
        p->father[i] = i;
        p->size[i] = 1;
    }
    p->cnt = n;
    return p;
}

void clear(UnionSet *u) {
    free(u->father);
    free(u->size);
    free(u);
}

int find(UnionSet *u, int ind) {
    if (u->father[ind] == ind) {
        return ind;
    }
    int father_ind = find(u, ind);
    u->father[ind] = father_ind;
    return father_ind;
}

int insert(UnionSet *u, int p, int q) {
    int father_p, father_q;
    father_p = find(u, p);
    father_q = find(u, q);
    if (father_p == father_q) return 0;
    if (u->size[father_p] > father_q) {
        father_p ^= father_q;
        father_q ^= father_p;
        father_p ^= father_q;
    }
    u->father[father_p] = father_q;
    u->size[father_q] += u->size[father_p];
    u->cnt--;
    return 1;
}
