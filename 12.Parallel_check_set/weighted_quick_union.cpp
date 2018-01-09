/*************************************************************************
	> File Name: weighted_quick_union.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月04日 星期六 12时05分09秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct UnionSet {
    int *father, *size;
    int n;
};

UnionSet *init(int n) {
    UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet));
    p->father = (int *)malloc(sizeof(int) * n);
    p-> size = (int *)malloc(sizeof(int) * n);
    p->n = n;
    for (int i = 0; i < n; ++i) {
        p->father[i] = i;
        p->size[i] = 1;
    }
    return p;
}

void clear(UnionSet *u) {
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int find(UnionSet *u, int ind) {
    if (u->father[ind] == ind) {
        return ind;
    }
    u->father[ind] = find(u, u->father[ind]);
    return u->father[ind];
}

int merge(UnionSet *u, int p, int q) {
    int father_p = find(u, p);
    int father_q = find(u, q);
    if (father_p == father_q) return 0;
    if (u->size[father_p] > u->size[father_q]) {
        u->father[father_q] = father_p;
        u->size[father_p] += u->size[father_q];
    } else { 
        u->father[father_p] = father_q;
        u->size[father_q] += u->size[father_p];
    }
    return 1;
}



int main() {
    return 0;
}
