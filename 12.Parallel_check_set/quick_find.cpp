/*************************************************************************
	> File Name: Parallel_check_set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月04日 星期六 10时09分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct UnionSet {
    int *color;
    int n;
};

UnionSet *init(int n) {
    UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet) * 1);
    p->n = n;
    p->color = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        p->color[i] = i;
    }
    return p;
}

void clear(UnionSet *u) {
    free(u->color);
    free(u);
    return ;
}

int find(UnionSet *u, int ind) {
    return u->color[ind];
}

int merge(UnionSet *u, int p, int q) {
    int color_p, color_q;
    color_p = find(u, p);
    color_q = find(u, q);
    if (color_p == color_q) return 0;
    for (int i = 0; i < u->n; ++i) {
        if (find(u, i) != color_p) continue;
        u->color[i] = color_q;
    }
    return 1;
}

void output(UnionSet *u) {
    for (int i = 0; i < u->n; ++i) {
        (i % 5 == 0) && printf("\n");
        printf("%d : %d", i, u->color[i]);
    }
    return ;
}

int main() {
    
    return 0;
}
