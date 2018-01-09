/*************************************************************************
	> File Name: hdu_1232.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月05日 星期日 16时04分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
    int *father, *size;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}
/*
UnionSet *init(int n) {
    UnionSet u;
    int a[n];
    int b[n];
    u.father = a;
    u.size = b;
    for (int i = 0; i < n; ++i) {
        u.father[i] = i;
        u.size[i] = 1;
    }
    return &u;
}*/
int find(UnionSet *u, int ind) {
    if (u->father[ind] == ind) {
        return ind;
    }
    u->father[ind] = find(u, u->father[ind]);
    return u->father[ind];
}

int merge(UnionSet *u, int a, int b) {
    int father_a = find(u, a);
    int father_b = find(u, b);
    if (father_a == father_b) {
        return 0;
    }
    if (u->size[father_a] > u->size[father_b]) {
        father_a ^= father_b;
        father_b ^= father_a;
        father_a ^= father_b;
    }
    u->father[father_a] = father_b;
    u->size[father_b] += u->size[father_a];
    return 1;
}

void clear(UnionSet *u) {
    free(u->father);
    free(u->size);
    free(u);
    return ;
}


int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        scanf("%d", &m);
        UnionSet *u = init(n);
        n--;
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            n -= merge(u, a, b);
        }
        printf("%d\n", n);
        clear(u);
    }
    return 0;
}
